extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "cadabra.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() {
	int state = 4;
	int i4, i5, i6, i7, i8, i9, i10;
	while (1) {
		i4 = __VERIFIER_nondet_int();
		i5 = __VERIFIER_nondet_int();
		i6 = __VERIFIER_nondet_int();
		i7 = __VERIFIER_nondet_int();
		i8 = __VERIFIER_nondet_int();
		i9 = __VERIFIER_nondet_int();
		i10 = __VERIFIER_nondet_int();
		if (i4 == 99 && state == 4) state ++;
		if (i5 == 97 && state == 5) state ++;
		if (i6 == 100 && state == 6) state ++;
		if (i7 == 97 && state == 7) state ++;
		if (i8 == 98 && state == 8) state ++;
		if (i9 == 114 && state == 9) state ++;
		if (i10 == 97 && state == 10) state ++;
		if (state == 11) {
			__VERIFIER_assert(0);
		}
	}
	return 0;
}
