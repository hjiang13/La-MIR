```c
int is_bored(char* str) {
  long len = strlen(str);
  if (len == 0) {
    return 0;
  }

  int count = 0;
  int space_count = 0;

  for (long i = 0; i < len; i++) {
    if (str[i] == ' ') {
      if (space_count == 0) {
        space_count = 1;
      }
      count += space_count;
    } else if (str[i] == 'I') {
      if (space_count == 1) {
        count += 1;
      }
      space_count = 0;
    } else {
      space_count = 0;
    }
  }

  return count;
}
```