// https://dl.acm.org/doi/10.1145/2001420.2001424
// fig 2, unsafe

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "godfroid-issta-2.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}


int main() { // x, y, z are inputs
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();
    int cy = 0, y1 = 0, done = 0;
    while (1) {
        //GX: 
	if (x <= 0) {
            done = 1;
            break;
        }
        y1 = y;
        while (1) {
        //GY: 
	if (y1 <= 0) break;
            y1--;
            cy = cy + 1;
        }
        //GZ: 
	if (z <= 0) break;
        x--;
        z--;
    }
    if (cy == y * 101) // 101
        __VERIFIER_assert(0);
    return 0;
}
