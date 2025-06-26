extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "abracadabra.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}



int main() {
	unsigned int x = 2;
	unsigned int M = __VERIFIER_nondet_uint();
	unsigned int N = __VERIFIER_nondet_uint();
	while (N-- > 1) {x = 2 * x;}
	while (M-- > 1) {x = x - 2;}
	__VERIFIER_assert(x!=1);
	return 0;
}
