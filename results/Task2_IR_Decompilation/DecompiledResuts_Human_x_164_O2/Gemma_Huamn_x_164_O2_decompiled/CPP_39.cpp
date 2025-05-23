```c
int prime_fib(int);

int prime_fib(int n) {
  int i = 1;
  int j = 2;
  int k = 0;
  while (k < n) {
    j = j + i;
    if (j < 4) {
      i = 1;
      j = 2;
      k = 0;
      continue;
    }
    for (int l = 2; l * l <= j; l++) {
      if (j % l == 0) {
        break;
      }
    }
    i = 1;
    j = 2;
    k++;
  }
  return j;
}
```
<|im_end|>