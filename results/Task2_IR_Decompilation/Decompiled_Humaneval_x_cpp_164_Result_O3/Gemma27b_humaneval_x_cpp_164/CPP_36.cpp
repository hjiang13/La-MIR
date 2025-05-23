```c
int fizz_buzzi(int x) {
  if (x > 0) {
    int i = 0;
    int sum = 0;
    while (1) {
      int r1 = i % 11;
      int r2 = i % 13;
      if ((r1 != 0) && (r2 != 0) || i == 0) {
        if (i == 0) {
          sum = sum;
        } else {
          while (i > 0) {
            int r = i % 10;
            if (r == 7) {
              sum++;
            }
            i = i / 10;
          }
        }
      }
      i++;
      if (i == x) {
        break;
      }
    }
    return sum;
  }
  return 0;
}

```