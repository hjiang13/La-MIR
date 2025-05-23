Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
int choose_num(int a, int b) {
  int c;
  if (b < a) {
    c = -1;
  } else if (b == a) {
    if (b % 2 == 1) {
      c = -1;
    } else {
      if (b % 2 == 1) {
        c = b - 1;
      } else {
        c = b;
      }
    }
  } else {
    if (b % 2 == 1) {
      c = b - 1;
    } else {
      c = b;
    }
  }
  return c;
}
```

Note that I've used the same variable names as in the IR code to maintain consistency. Also, I've kept the same logic and structure as the IR code, but represented it in C syntax.