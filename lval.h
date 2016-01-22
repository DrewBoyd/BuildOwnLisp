/*
** lval - definition of the lisp value type
*/

#ifndef lval_h
#define lval_h

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "mpc.h"
#include "lerror.h"

struct lval;
struct lenv;
typedef struct lval lval;
typedef struct lenv lenv;

enum { LVAL_NUM, LVAL_ERR, LVAL_SYM, LVAL_SEXPR, LVAL_QEXPR, LVAL_FUN };
char* ltype_name(int t);

typedef lval*(*lbuiltin)(lenv*, lval*);

typedef struct lval
{
  int type;

  long num;
  char* err;
  char* sym;
  
  lbuiltin builtin;
  lenv* env;
  lval* formals;
  lval* body;

  int count;
  struct lval** cell;
} lval;

// Constructors
lval* lval_num(long x);
lval* lval_err(char* fmt, ...);
lval* lval_sym(char* m);
lval* lval_fun(lbuiltin func);
lval* lval_lambda(lval* formals, lval* body);
lval* lval_sexpr(void);
lval* lval_qexpr(void);

// Destructor
void lval_del(lval* v);

// Copier
lval* lval_copy(lval* v);

// lval list operators
lval* lval_add(lval* v, lval* x);
lval* lval_pop(lval* v, int i);
lval* lval_take(lval* v, int i);
lval* lval_join(lval* x, lval* y);

#endif
