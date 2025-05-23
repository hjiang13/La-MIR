```c
int largest_prime_factor(int n) {
  if (n < 4) {
    return n;
  }
  int i = 2;
  int j = n;
  while (1) {
    if (j % i == 0) {
      if (j > i) {
        j /= i;
        if (j % i == 0) {
          continue;
        }
      }
      return j;
    }
    i++;
    if (i * i > j) {
      return j;
    }
  }
}

```
<|im_end|>