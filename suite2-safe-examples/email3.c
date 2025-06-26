extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "email3.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() {
	unsigned int i = 2;
	unsigned int N = __VERIFIER_nondet_uint();
	while (N-->1) {i*=2;}
	while (i > 0) {i -= 2;}
	__VERIFIER_assert(i>=0);
}

