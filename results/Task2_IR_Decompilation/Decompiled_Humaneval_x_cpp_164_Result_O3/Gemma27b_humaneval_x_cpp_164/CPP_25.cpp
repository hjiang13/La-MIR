```c
#include <stdlib.h>

void factorizei(int* ret, int input) {
  int *begin = NULL;
  int *end = NULL;
  int *curr = NULL;

  if (input < 4) {
    *ret = input;
    return;
  }

  begin = (int*)malloc(sizeof(int) * input);
  if (begin == NULL) {
    return;
  }

  end = begin;
  curr = begin;
  *end = input;
  end++;

  for (int i = 2; i * i <= input; i++) { if (input % i == 0) {

    *end = i;
    end++;
    input /= i;
    i--;
  }
  }

  if (input > 1) {
    *end = input;
    end++;
  }

  int *tmp = (int*)realloc(begin, sizeof(int) * (end - begin));
  if (tmp == NULL) {
    free(begin);
    return;
  }

  begin = tmp;
  end = begin + (end - begin);

  for (int i = 0; i < end - begin; i++) {
    ret[i] = begin[i];
  }

  free(begin);
}

```