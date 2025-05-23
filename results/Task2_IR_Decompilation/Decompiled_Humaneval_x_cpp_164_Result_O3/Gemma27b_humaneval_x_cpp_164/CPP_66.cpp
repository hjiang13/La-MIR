```c
int digitSum(const char* str) {
  int len = strlen(str);
  if (len == 0) {
    return 0;
  }
  int sum = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      sum += str[i] - '0';
    }
  }
  return sum;
}
```