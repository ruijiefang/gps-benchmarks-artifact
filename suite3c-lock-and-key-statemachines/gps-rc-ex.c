extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "gps-rc-ex.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() {
	int s0, s1, s2, c;
	int state =0;
	while (1) {
		c = __VERIFIER_nondet_int();
		s0 = __VERIFIER_nondet_int();
		s1 = __VERIFIER_nondet_int();
		s2 = __VERIFIER_nondet_int();
		if (c == 68 && state == 0) state = 1;
		if (c == 79 && state == 1) state = 2;
		if (c == 71 && state == 2) state = 3;
		if (state == 3 && s0 == 67 && s1 == 65 && s2 == 84) {
			__VERIFIER_assert(0);
		}
	}
	return 0;
}

