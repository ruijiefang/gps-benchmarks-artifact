extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "count_up_down-2.c", 3, "reach_error"); }

//extern void sassert(int);

//void __VERIFIER_error() {
//	sassert(0);
//}

//extern void __VERIFIER_error();

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {__VERIFIER_error();}
  }
  return;
}


//#include "seahorn/seahorn.h"

unsigned int __VERIFIER_nondet_uint();

int main()
{
  unsigned int n = __VERIFIER_nondet_uint();
  unsigned int x=n, y=0;
  while(x>0)
  {
    x--;
    y++;
  }
//  sassert(y!=n);
  __VERIFIER_assert(y!=n);
}
