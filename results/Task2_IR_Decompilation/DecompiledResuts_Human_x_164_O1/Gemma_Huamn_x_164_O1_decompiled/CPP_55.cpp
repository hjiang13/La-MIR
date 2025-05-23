```c
int _Z3fibi(int a0) {
  int A[1000];
  A[0] = 0;
  A[1] = 1;
  if (a0 < 2) {
    return A[a0];
  }
  for (int i = 2; i < a0 + 1; ++i) {
    A[i] = A[i - 1] + A[i - 2];
  }
  return A[a0];
}
```

<|im_end|>