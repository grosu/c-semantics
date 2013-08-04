/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
/* compiler builtin: 
   void __builtin_va_end(__builtin_va_list  ) ;  */
/* compiler builtin: 
   void __builtin_va_copy(__builtin_va_list  , __builtin_va_list  ) ;  */
/* compiler builtin: 
   void __builtin_va_arg(__builtin_va_list  , unsigned long  , void * ) ;  */
/* compiler builtin: 
   void __builtin_va_start(__builtin_va_list  ) ;  */
extern  __attribute__((__nothrow__, __noreturn__)) void abort(void)  __attribute__((__leaf__)) ;
int foo_arg  ;
int bar_arg  ;
long x  ;
double d  ;
va_list gap  ;
va_list *pap  ;
void foo(int v , va_list ap ) 
{ 

  {
  switch (v) {
  case 5: 
  foo_arg = __builtin_va_arg(ap, int );
  break;
  default: 
  abort();
  }
  return;
}
}
void bar(int v ) 
{ double tmp ;
  long tmp___0 ;
  long long tmp___1 ;
  long double tmp___2 ;
  int tmp___3 ;

  {
  if (v == 16390) {
    tmp = __builtin_va_arg(gap, double );
    if (tmp != 17.0) {
      abort();
    } else {
      tmp___0 = __builtin_va_arg(gap, long );
      if (tmp___0 != 129L) {
        abort();
      }
    }
  } else {
    if (v == 16392) {
      tmp___1 = __builtin_va_arg(*pap, long long );
      if (tmp___1 != 14LL) {
        abort();
      } else {
        tmp___2 = __builtin_va_arg(*pap, long double );
        if (tmp___2 != 131.0L) {
          abort();
        } else {
          tmp___3 = __builtin_va_arg(*pap, int );
          if (tmp___3 != 17) {
            abort();
          }
        }
      }
    }
  }
  bar_arg = v;
  return;
}
}
void f0(int i  , ...) 
{ 

  {
  return;
}
}
void f1(int i  , ...) 
{ va_list ap ;

  {
  __builtin_va_start(ap, i);
  __builtin_va_end(ap);
  return;
}
}
void f2(int i  , ...) 
{ va_list ap ;

  {
  __builtin_va_start(ap, i);
  bar((int )d);
  x = __builtin_va_arg(ap, long );
  bar((int )x);
  __builtin_va_end(ap);
  return;
}
}
void f3(int i  , ...) 
{ va_list ap ;

  {
  __builtin_va_start(ap, i);
  d = __builtin_va_arg(ap, double );
  __builtin_va_end(ap);
  return;
}
}
void f4(int i  , ...) 
{ va_list ap ;

  {
  __builtin_va_start(ap, i);
  x = __builtin_va_arg(ap, double );
  foo(i, ap);
  __builtin_va_end(ap);
  return;
}
}
void f5(int i  , ...) 
{ va_list ap ;

  {
  __builtin_va_start(ap, i);
  __builtin_va_copy(gap, ap);
  bar(i);
  __builtin_va_end(ap);
  __builtin_va_end(gap);
  return;
}
}
void f6(int i  , ...) 
{ va_list ap ;
  long tmp ;
  long tmp___0 ;

  {
  __builtin_va_start(ap, i);
  bar((int )d);
  tmp = __builtin_va_arg(ap, long );
  tmp___0 = __builtin_va_arg(ap, long );
  x = __builtin_va_arg(ap, long );
  bar((int )x);
  __builtin_va_end(ap);
  return;
}
}
void f7(int i  , ...) 
{ va_list ap ;

  {
  __builtin_va_start(ap, i);
  pap = & ap;
  bar(i);
  __builtin_va_end(ap);
  return;
}
}
void f8(int i  , ...) 
{ va_list ap ;

  {
  __builtin_va_start(ap, i);
  pap = & ap;
  bar(i);
  d = __builtin_va_arg(ap, double );
  __builtin_va_end(ap);
  return;
}
}
int main(void) 
{ 

  {
  f0(1);
  f1(2);
  d = 31.0;
  f2(3, 28L);
  if (bar_arg != 28) {
    abort();
  } else {
    if (x != 28L) {
      abort();
    }
  }
  f3(4, 131.0);
  if (d != 131.0) {
    abort();
  }
  f4(5, 16.0, 128);
  if (x != 16L) {
    abort();
  } else {
    if (foo_arg != 128) {
      abort();
    }
  }
  f5(16390, 17.0, 129L);
  if (bar_arg != 16390) {
    abort();
  }
  f6(7, 12L, 14L, -31L);
  if (bar_arg != -31) {
    abort();
  }
  f7(16392, 14LL, 131.0L, 17, 26.0);
  if (bar_arg != 16392) {
    abort();
  }
  f8(16392, 14LL, 131.0L, 17, 27.0);
  if (bar_arg != 16392) {
    abort();
  } else {
    if (d != 27.0) {
      abort();
    }
  }
  return (0);
}
}