#include "repl.h"

///////////////////////////////////////////////////
// READ
lval* lval_read_num(mpc_ast_t* t)
{
  errno = 0;
  long x = strtol(t->contents, NULL, 10);
  return errno != ERANGE
    ? lval_num(x)
    : lval_err("Invalid number.");
}

lval* lval_read(mpc_ast_t* t)
{
  if (strstr(t->tag, "number"))
    return lval_read_num(t);

  if (strstr(t->tag, "symbol"))
    return lval_sym(t->contents);

  lval* x = NULL;
  if (strcmp(t->tag, ">") == 0 || strstr(t->tag, "sexpr"))
    x = lval_sexpr();

  if (strstr(t->tag, "qexpr"))
    x = lval_qexpr();

  for (int i = 0; i < t->children_num; i++)
  {
    if (strcmp(t->children[i]->contents, "(") == 0 ||
        strcmp(t->children[i]->contents, ")") == 0 ||
        strcmp(t->children[i]->contents, "{") == 0 ||
        strcmp(t->children[i]->contents, "}") == 0 ||
        strcmp(t->children[i]->tag, "regex") == 0)
    {
      continue;
    }
    x = lval_add(x, lval_read(t->children[i]));
  }

  return x;
}

///////////////////////////////////////////////////
// EVAL
lval* lval_eval_sexpr(lenv* e, lval* v)
{
  // Evaluate children
  for (int i = 0; i < v->count; i++)
    v->cell[i] = lval_eval(e, v->cell[i]);

  // Error checking
  for (int i = 0; i < v->count; i++)
    if (v->cell[i]->type == LVAL_ERR)
      return lval_take(v, i);

  // Empty expression
  if (v->count == 0)
    return v;

  // Single expression
  if (v->count == 1)
    return lval_take(v, 0);

  // First element should be a function
  lval* f = lval_pop(v, 0);
  if (f->type != LVAL_FUN)
  {
    lval_del(f);
    lval_del(v);
    return lval_err("First element of s-expression is not a function.");
  }

  // Call builtin with op
  lval* result = f->builtin(e, v);
  lval_del(f);
  return result;
}

lval* lval_eval(lenv* e, lval* v)
{
  if (v->type == LVAL_SYM)
  {
    lval* x = lenv_get(e, v);
    lval_del(v);
    return x;
  }

  // Eval s-expressions
  if (v->type == LVAL_SEXPR)
    return lval_eval_sexpr(e, v);

  // All other types remain the same
  return v;
}

///////////////////////////////////////////////////
// PRINT
void lval_expr_print(lval* v, char open, char close)
{
  putchar(open);

  for (int i = 0; i < v->count; i++)
  {
    lval_print(v->cell[i]);
    if (i != (v->count-1))
      putchar(' ');
  }

  putchar(close);
}

void lval_print(lval* v)
{
  switch (v->type)
  {
  case LVAL_NUM:
    printf("%li", v->num);
    break;
  case LVAL_ERR:
    printf("Error: %s", v->err);
    break;
  case LVAL_SYM:
    printf("%s", v->sym);
    break;
  case LVAL_SEXPR:
    lval_expr_print(v, '(', ')');
    break;
  case LVAL_QEXPR:
    lval_expr_print(v, '{', '}');
    break;
  case LVAL_FUN:
    if (v->builtin)
      printf("<function>");
    else
    {
      printf("(\\ ");
      lval_print(v->formals);
      putchar(' ');
      lval_print(v->body);
      putchar(')');
    }
    break;
  }
}

void lval_println(lval* v)
{
  lval_print(v);
  putchar('\n');
}
