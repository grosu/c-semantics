/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

extern  __attribute__((__nothrow__, __noreturn__)) void abort(void)  __attribute__((__leaf__)) ;
extern  __attribute__((__nothrow__, __noreturn__)) void exit(int __status )  __attribute__((__leaf__)) ;
int add(int a , int b , int c , int d , int e , int f , int g , int h , int i , int j ,
        int k , int l , int m ) 
{ 

  {
  return ((((((((((((a + b) + c) + d) + e) + f) + g) + h) + i) + j) + k) + l) + m);
}
}
int main(void) 
{ int tmp ;

  {
  tmp = add(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
  if (tmp != 91) {
    abort();
  }
  exit(0);
}
}