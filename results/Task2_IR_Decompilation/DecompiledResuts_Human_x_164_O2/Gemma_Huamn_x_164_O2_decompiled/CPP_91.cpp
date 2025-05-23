```c
int is_bored(const char* str) {
  int len = strlen(str);
  if (len == 0) {
    return 0;
  }

  int count = 0;
  int state = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == ' ') {
      if (state == 1) {
        count++;
      }
      state = 0;
    } else if (str[i] == 'I') {
      if (state == 1) {
        count++;
      }
      state = 1;
    } else {
      state = 0;
    }
  }
  return count;
}
```