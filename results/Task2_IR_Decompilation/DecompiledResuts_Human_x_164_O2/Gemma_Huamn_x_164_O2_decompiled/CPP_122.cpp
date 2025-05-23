```c
int add_elements(int *a, int n) {
  if (n <= 0) {
     return 0;
  }

  int sum = 0;

  for (int i = 0; i < n; i++){
    if (a[i] < 199){
      sum += a[i] + 99;
    }
  }

  return sum;
}
```