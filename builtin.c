#include "builtin.h"

lval* lval_eval(lenv* e, lval* v);

lval* builtin_op(lenv* e, lval* a, char* op)
{
  // Ensure all arguments are numbers
  for (int i = 0; i < a->count; i++)
    LASSERT_TYPE("+", a, i, LVAL_NUM);

  // Pop the first element
  lval* x = lval_pop(a, 0);

  // If minus sign and no arguments, treat as unary negation
  if (strcmp(op, "-") == 0 && a->count == 0)
    x->num = -x->num;

  while (a->count > 0)
  {
    lval* y = lval_pop(a, 0);

    if (strcmp(op, "+") == 0)
      x->num += y->num;
    if (strcmp(op, "-") == 0)
      x->num -= y->num;
    if (strcmp(op, "*") == 0)
      x->num *= y->num;
    if (strcmp(op, "/") == 0)
    {
      // Check for div by zero first
      if (y->num == 0)
      {
        lval_del(x);
        lval_del(y);
        x = lval_err("Division by zero.");
        break;
      }
      x->num /= y->num;
    }

    lval_del(y);
  }

  lval_del(a);
  return x;
}

// Math - addition
lval* builtin_add(lenv* e, lval* a)
{
  return builtin_op(e, a, "+");
}

// Math - subtraction
lval* builtin_sub(lenv* e, lval* a)
{
  return builtin_op(e, a, "-");
}

// Math - multiplication
lval* builtin_mul(lenv* e, lval* a)
{
  return builtin_op(e, a, "*");
}

// Math - division
lval* builtin_div(lenv* e, lval* a)
{
  return builtin_op(e, a, "/");
}

// Make qexpr with given args
lval* builtin_list(lenv* e, lval* a)
{
  a->type = LVAL_QEXPR;
  return a;
}

// Return first element of a qexpr
lval* builtin_head(lenv* e, lval* a)
{
  LASSERT_NUM("head", a, 1);
  LASSERT_TYPE("head", a, 0, LVAL_QEXPR);
  LASSERT_NOT_EMPTY("head", a, 0);

  lval* v = lval_take(a, 0);
  while (v->count > 1)
    lval_del(lval_pop(v, 1));

  return v;
}

// Return qexpr with first element removed
lval* builtin_tail(lenv* e, lval* a)
{
  LASSERT_NUM("tail", a, 1);
  LASSERT_TYPE("tail", a, 0, LVAL_QEXPR);
  LASSERT_NOT_EMPTY("tail", a, 0);

  lval* v = lval_take(a, 0);
  lval_del(lval_pop(v, 0));

  return v;
}

// Combine multiple qexprs
lval* builtin_join(lenv* e, lval* a)
{
  for (int i = 0; i < a->count; i++)
    LASSERT_TYPE("join", a, i, LVAL_QEXPR);

  lval* x = lval_pop(a, 0);

  while (a->count)
    x = lval_join(x, lval_pop(a, 0));

  lval_del(a);

  return x;
}

// Evaluate a qexpr as if it is a sexpr
lval* builtin_eval(lenv* e, lval* a)
{
  LASSERT_NUM("eval", a, 1);
  LASSERT_TYPE("eval", a, 0, LVAL_QEXPR);

  lval* x = lval_take(a, 0);
  x->type = LVAL_SEXPR;
  return lval_eval(e, x);
}

lval* builtin_var(lenv* e, lval* a, char* func)
{
  LASSERT_TYPE(func, a, 0, LVAL_QEXPR);

  lval* syms = a->cell[0];

  for (int i = 0; i < syms->count; i++)
    LASSERT(a, syms->cell[i]->type == LVAL_SYM,
      "Function '%s' cannot define a non-symbol.  Got %s, Expected %s.",
      func, ltype_name(syms->cell[i]->type), ltype_name(LVAL_SYM));

  LASSERT(a, syms->count == a->count - 1,
    "Function '%s' passed too many arguments for symbols.  Got %i, Expected %i.",
    func, syms->count, a->count - 1);

  for (int i = 0; i < syms->count; i++)
  {
    if (strcmp(func, "def") == 0)
      lenv_def(e, syms->cell[i], a->cell[i+1]);
    
    if (strcmp(func, "=") == 0)
      lenv_put(e, syms->cell[i], a->cell[i+1]);
  }

  lval_del(a);
  return lval_sexpr();
}

lval* builtin_def(lenv* e, lval* a)
{
  return builtin_var(e, a, "def");
}

lval* builtin_put(lenv* e, lval* a)
{
  return builtin_var(e, a, "=");
}

lval* builtin_lambda(lenv* e, lval* a)
{
  LASSERT_NUM("\\", a, 2);
  LASSERT_TYPE("\\", a, 0, LVAL_QEXPR);
  LASSERT_TYPE("\\", a, 1, LVAL_QEXPR);
  
  for (int i = 0; i < a->cell[0]->count; i++)
  {
    LASSERT(a, (a->cell[0]->cell[i]->type == LVAL_SYM),
      "Cannot define non-symbol.  Got %s, Expected %s.",
      ltype_name(a->cell[0]->cell[i]->type), ltype_name(LVAL_SYM));
  }
  
  lval* formals = lval_pop(a, 0);
  lval* body = lval_pop(a, 0);
  lval_del(a);
  
  return lval_lambda(formals, body);
}

//////////////////////////////////////////////////////////////

void lenv_add_builtin(lenv* e, char* name, lbuiltin func)
{
  lval* k = lval_sym(name);
  lval* v = lval_fun(func);
  lenv_put(e, k, v);
  lval_del(k);
  lval_del(v);
}

void lenv_add_builtins(lenv* e)
{
  // List functions
  lenv_add_builtin(e, "list", builtin_list);
  lenv_add_builtin(e, "head", builtin_head);
  lenv_add_builtin(e, "tail", builtin_tail);
  lenv_add_builtin(e, "join", builtin_join);
  lenv_add_builtin(e, "eval", builtin_eval);

  // Math functions
  lenv_add_builtin(e, "+", builtin_add);
  lenv_add_builtin(e, "-", builtin_sub);
  lenv_add_builtin(e, "*", builtin_mul);
  lenv_add_builtin(e, "/", builtin_div);

  // Variable functions
  lenv_add_builtin(e, "\\",  builtin_lambda);
  lenv_add_builtin(e, "def", builtin_def);
  lenv_add_builtin(e, "=",   builtin_add);
}
