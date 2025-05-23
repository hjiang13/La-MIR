```c
#include <stdlib.h>
#include <string.h>

struct __cxx11__basic_string {
  void *__data;
  size_t __size;
  size_t __capacity;
};

void parse_nested_parens(struct __cxx11__basic_string *result,
                         const struct __cxx11__basic_string *input) {
  struct __cxx11__basic_string temp;
  temp.__data = NULL;
  temp.__size = 0;
  temp.__capacity = 0;
  char *cursor = input->__data;
  size_t i;
  int nesting = 0;
  int balance = 0;

  while (*cursor) {
    if (*cursor == '(') {
      nesting++;
      balance++;
    } else if (*cursor == ')') {
      nesting--;
      balance--;
    }
    if (nesting == 0 && balance > 0) {
      size_t new_size = temp.__size + 1;
      if (new_size > temp.__capacity) {
        temp.__capacity = new_size * 2;
        temp.__data = realloc(temp.__data, temp.__capacity);
      }
      ((char *)temp.__data)[temp.__size] = *cursor;
      temp.__size = new_size;
    }
    cursor++;
  }

  result->__data = temp.__data;
  result->__size = temp.__size;
  result->__capacity = temp.__capacity;

  free(temp.__data);
}

```