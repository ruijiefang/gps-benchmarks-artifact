extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "email1.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() {
	int i = 0;
	while (__VERIFIER_nondet_int()) {
		if (__VERIFIER_nondet_int()) {
			i += 2;
		} else {
			i += 4;
		}
	}
	while (i > 0) {i -= 2;}
	__VERIFIER_assert(i>=0);
}

