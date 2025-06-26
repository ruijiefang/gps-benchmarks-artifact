// Taken from Majumdar&Sen, "Hybrid Concolic Testing", ICSE 2007

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "diamond_1-1.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}





int main() {
int s0,s1,s2,s3,s4,s5;
int c;
int state = 0;
while (1) {
c = __VERIFIER_nondet_int();
s0 = __VERIFIER_nondet_int();
s1 = __VERIFIER_nondet_int();
s2 = __VERIFIER_nondet_int();
s3 = __VERIFIER_nondet_int();
s4 = __VERIFIER_nondet_int();
s5 = __VERIFIER_nondet_int();

/* a simple state machine */
if (c == 91 && state == 0) state = 1;
if (c == 40 && state == 1) state = 2;
if (c == 123 && state == 2) state = 3;
if (c == 126 && state == 3) state = 4;
if (c == 97 && state == 4) state = 5;
if (c == 120 && state == 5) state = 6;
if (c == 125 && state == 6) state = 7;
if (c == 41 && state == 7) state = 8;
if (c == 93 && state == 8) state = 9;
if (s0 == 114 && s1 == 101
&& s2 == 116 && s3 == 101
&& s4 == 115 && s5 == 0
&& state == 9) {
__VERIFIER_assert(0);
} 
} 
}
