/*
** lerror - error handling macros for lisp
*/

#ifndef lerror_h
#define lerror_h

char* ltype_name(int t);

// FYI...
// 'if (!cond)'  was not working as expected.
// 'if (!(cond))  fixed the issue

#define LASSERT(args, cond, fmt, ...)         \
  if (!(cond))                                \
  {                                           \
    lval* err = lval_err(fmt, ##__VA_ARGS__); \
    lval_del(args);                           \
    return err;                               \
  }

#define LASSERT_TYPE(func, args, index, expect)                                   \
  LASSERT(args, args->cell[index]->type == expect,                                \
    "Function '%s' passed incorrect type for argument %i.  Got %s, Expected %s.", \
    func, index, ltype_name(args->cell[index]->type), ltype_name(expect));

#define LASSERT_NUM(func, args, num)                                              \
  LASSERT(args, args->count == num,                                               \
    "Function '%s' passed incorrect number of arguments.  Got %i, Expected %i.",  \
    func, args->count, num);

#define LASSERT_NOT_EMPTY(func, args, index)                                      \
  LASSERT(args, args->cell[index]->count != 0,                                    \
    "Function '%s' passed {} for argument %i.  Expected to be non-empty.",        \
    func, index);

#endif