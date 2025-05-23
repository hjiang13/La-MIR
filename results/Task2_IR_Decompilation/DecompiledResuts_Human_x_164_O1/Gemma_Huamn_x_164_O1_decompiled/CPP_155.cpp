```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct std_vector {
  void **_M_impl;
} std_vector;

typedef struct std__string {
  char *_M_dataplus;
  size_t _M_string_length;
} std__string;

extern void __assert_fail(const char *__assertion, const char *__file, unsigned int __line, const char *__function) __attribute__((noreturn));

extern int _abs(int __x) __attribute__((__const__));
extern int vsnprintf(char *__restrict __s, size_t __n, const char *__format, __builtin_va_list __arg);

std__string* even_odd_counti(std_vector* __ret, int __n) {
  std__string __s;
  char __buf[32];

  __s._M_dataplus = (char *)malloc(32);
  __s._M_string_length = 32;

  sprintf(__buf, "%d", _abs(__n));
  vsnprintf(__s._M_dataplus, 32, "%s", __buf);

  size_t __i = 0;
  size_t __j = 0;
  int __count_even = 0;
  int __count_odd = 0;

  while (__i < __s._M_string_length) {
    if (__s._M_dataplus[__i] - '0' % 2 == 0) {
      __count_even++;
    } else {
      __count_odd++;
    }

    __i++;
  }

  __ret->_M_impl = malloc(sizeof(int)*2);
  __ret->_M_impl[0] = __count_even;
  __ret->_M_impl[1] = __count_odd;

  return &__s;

}

int main() {

  std_vector __ret;
  std__string* __s = even_odd_counti(&__ret, 12345);

  printf("%d evens, %d odds\n", *(int *)__ret._M_impl[0], *(int *)__ret._M_impl[1]);
  free(__s->_M_dataplus);
  free(__ret._M_impl);
  return 0;
}
```