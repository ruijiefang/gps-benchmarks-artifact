extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "abracadabraabra.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() {
	int state = 0;
	int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
	int j0, j1, j2, j3, j4, j5, j6, j7, j8, j9, j10;
	while (1) {
		i0 =__VERIFIER_nondet_int();
		i1 = __VERIFIER_nondet_int();
		i2 = __VERIFIER_nondet_int();
		i3 = __VERIFIER_nondet_int();
		i4 = __VERIFIER_nondet_int();
		i5 = __VERIFIER_nondet_int();
		i6 = __VERIFIER_nondet_int();
		i7 = __VERIFIER_nondet_int();
		i8 = __VERIFIER_nondet_int();
		i9 = __VERIFIER_nondet_int();
		i10 = __VERIFIER_nondet_int();
		j0 = __VERIFIER_nondet_int();
		j1 = __VERIFIER_nondet_int();
		j2 = __VERIFIER_nondet_int();
		j3 = __VERIFIER_nondet_int();
		if (i0 == 97 && state == 0) state++;
		if (i1 == 98 && state == 1) state ++;
		if (i2 == 114 && state == 2) state ++;
		if (i3 == 97 && state == 3) state ++;
		if (i4 == 99 && state == 4) state ++;
		if (i5 == 97 && state == 5) state ++;
		if (i6 == 100 && state == 6) state ++;
		if (i7 == 97 && state == 7) state ++;
		if (i8 == 98 && state == 8) state ++;
		if (i9 == 114 && state == 9) state ++;
		if (i10 == 97 && state == 10) state ++;
		
                if (j0 == 97 && state == 11) state++;
                if (j1 == 98 && state == 12) state ++;
                if (j2 == 114 && state == 13) state ++;
                if (j3 == 97 && state == 14) state ++;
		if (state == 15) {
			__VERIFIER_assert(0);
		}
	}
	return 0;
}
