```c
int smallest_change(int* arr, int size) {
  int* end = arr + size;
  int count = 0;
  for (int* i = arr + 1; i < end; i++) {
    if (*i != *(i - 1)) {
      count++;
    }
  }
  return count;
}
```<|im_end|>