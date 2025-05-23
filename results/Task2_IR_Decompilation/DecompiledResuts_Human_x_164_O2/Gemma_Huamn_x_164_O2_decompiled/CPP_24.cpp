```c
int largest_divisori(int);

int largest_divisori(int n) {
  if (n < 4) {
    return 1;
  }
  int i = 2;
  while (true) {
    if (n % i == 0) {
      return n / i;
    }
    i++;
    if (i * i > n) {
      return 1;
    }
  }
}
```