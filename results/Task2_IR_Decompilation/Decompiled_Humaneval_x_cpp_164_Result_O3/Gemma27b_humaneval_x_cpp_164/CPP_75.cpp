```c
int _Z17is_multiply_primei(int);

int _Z17is_multiply_primei(int n) {
  if (n < 4) {
    return n == 2;
  }
  int i = 2;
  int count = 0;
  int temp = n;
  while (1) {
    int remainder = temp % i;
    if (temp > i && remainder == 0) {
      count++;
      temp /= i;
      remainder = temp % i;
      if (temp > i && remainder == 0) {
        continue;
      }
    }
    i++;
    int square = i * i;
    if (square > temp) {
      break;
    }
  }
  return count == 0;
}
```