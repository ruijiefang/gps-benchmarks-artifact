extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "ex3-a.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() {
	int r = 0;
	int N = __VERIFIER_nondet_int();
	if (N > 0xfffff) { return 0; }
	while (N > 0) {
		r = r + N--;
	}
	__VERIFIER_assert(r != 2);
	return 0;
}
