// https://dl.acm.org/doi/10.1145/2001420.2001424
// fig 1, unsafe

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "godfroid-issta-1b.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() {  
    int x = __VERIFIER_nondet_int();// x is an input
    int c = 0, p = 0;
    while (1) {
        if (x <= 0) break;
        // if (c == 50) __VERIFIER_assert(false);  /* error1 */
        c = c + 1;
        p = p + c;
        x = x - 1;
    }
    if (c == 3000) __VERIFIER_assert(0);  /* error2 */
    return 0;
}
