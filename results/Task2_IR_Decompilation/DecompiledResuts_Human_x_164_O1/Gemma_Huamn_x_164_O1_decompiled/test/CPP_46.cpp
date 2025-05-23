int fib4i(int a0) {
  int a1[100];
  for (int i = 0; i < 100; i++) {
    a1[i] = 0;
  }
  a1[0] = 0;
  a1[1] = 0;
  a1[2] = 2;
  if (a0 < 4) {
    return a1[a0];
  }
  int a2 = a0 + 1;
  int a3 = a1[3];
  for (int i = 4; i < a2; i++) {
    int a4 = a1[i - 2];
    int a5 = a1[i - 3];
    int a6 = a1[i - 4];
    int a7 = a4 + a3;
    int a8 = a7 + a5;
    a1[i] = a8;
    a3 = a8;
  }
  return a1[a0];
}
```

<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
