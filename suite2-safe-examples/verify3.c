extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "diamond_1-1.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}



int main()
{
  int i = 1;  
  int havoc = __VERIFIER_nondet_int();
  while(havoc>0){ i = 10 * i; havoc--; }
  int j = 0;
  while(i>0){j++;i--;}
  __VERIFIER_assert(j!=791);
  return 0;
}

