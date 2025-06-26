extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "godefroid-ndss08.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() {
	int cnt = 0;
	int i0, i1, i2, i3;
	while (1) {
		i0 =__VERIFIER_nondet_int();
		i1 = __VERIFIER_nondet_int();
		i2 = __VERIFIER_nondet_int();
		i3 = __VERIFIER_nondet_int();
		if (i0 == 98 && cnt == 0) cnt += 1;
		if (i1 == 97 && cnt == 1) cnt += 1;
		if (i2 == 100 && cnt == 2) cnt += 1;
		if (i3 == 33 && cnt == 3) cnt += 1;
		if (cnt >= 4) {
			__VERIFIER_assert(0);
		}
	}
	return 0;
}
