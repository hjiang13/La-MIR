```c
int will_it_fly(int* arr, int size, int target) {
  int* end = arr + size;
  int* start = arr;
  if (start == end) {
    return 0;
  }
  long long len = end - start;
  long long mid = (len / 2);
  while (1) {
    int left = *(start + mid);
    int right = *(end - mid - 1);
    if (left == right) {
      left += mid;
      if (left == target) {
        return 1;
      }
      mid++;
      if (mid == len) {
        return 0;
      }
    } else {
      return 0;
    }
  }
}

```