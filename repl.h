/*
** repl - Read/Evalulate/Print functions
*/

#ifndef repl_h
#define repl_h

#include "lerror.h"
#include "lval.h"
#include "lenv.h"

///////////////////////////////////////////////////
// READ
lval* lval_read_num(mpc_ast_t* t);
lval* lval_read(mpc_ast_t* t);

///////////////////////////////////////////////////
// EVAL
lval* lval_eval_sexpr(lenv* e, lval* v);
lval* lval_eval(lenv* e, lval* v);
lval* lval_call(lenv* e, lval* f, lval* a);

///////////////////////////////////////////////////
// PRINT
void lval_expr_print(lval* v, char open, char close);
void lval_print(lval* v);
void lval_println(lval* v);

#endif
