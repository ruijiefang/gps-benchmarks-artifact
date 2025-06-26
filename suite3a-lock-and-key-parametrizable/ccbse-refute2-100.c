extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "ccbse-refute2.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}



int main() {
	int m, n, g_i, f_i, a, sum;
	m = __VERIFIER_nondet_int();
	n = __VERIFIER_nondet_int();
	// foo();
	if (m >= 30) {
		// g(m, n)
		int g_i;
		for(g_i = 0; g_i < 30000; g_i++) {
			if (m==g_i) {
				// f(m, n)
				sum = 0;
				for(f_i = 0; f_i < 6; f_i++) {
					a = n % 2;
					if (a) sum += (a + 1);
					n /= 2;
				}
				while (1) {
					if (sum==0 && m == 100) {
						__VERIFIER_assert(0); //error
					}
				}
			}
		}
	}
	return 0;
}
