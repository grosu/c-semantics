/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

extern  __attribute__((__nothrow__, __noreturn__)) void abort(void)  __attribute__((__leaf__)) ;
extern  __attribute__((__nothrow__, __noreturn__)) void exit(int __status )  __attribute__((__leaf__)) ;
int f(void) 
{ int var ;

  {
  var = 7;
  if (var / 7 == 1) {
    return (var / 7);
  }
  return (0);
}
}
int main(void) 
{ int tmp ;

  {
  tmp = f();
  if (tmp != 1) {
    abort();
  }
  exit(0);
}
}