```c
int move_one_ball(int *arr, int len) {
  if (len == 0) {
    return 1;
  }
  if (len > 1) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }
  return arr[0];
}
```