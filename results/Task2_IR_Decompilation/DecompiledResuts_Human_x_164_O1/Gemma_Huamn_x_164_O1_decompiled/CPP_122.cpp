```c
int add_elements(int* x, int size) {
  if (size > 0) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
      int val = x[i] + 99;
      sum += (val < 199) ? val : 0;
    }
    return sum;
  } else {
    return 0;
  }
}
```