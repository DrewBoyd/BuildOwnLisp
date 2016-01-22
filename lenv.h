/*
** lenv - lisp environment
*/

#ifndef lenv_h
#define lenv_h

#include "lerror.h"
#include "lval.h"

struct lenv
{
  lenv* par;
  int count;
  char** syms;
  lval** vals;
};

lenv* lenv_new(void);
void lenv_del(lenv* e);

lval* lenv_get(lenv* e, lval* k);
void lenv_put(lenv* e, lval* k, lval* v);
lenv* lenv_copy(lenv* e);

#endif
