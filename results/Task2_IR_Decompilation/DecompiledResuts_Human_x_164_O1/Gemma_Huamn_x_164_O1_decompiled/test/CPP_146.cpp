#include <stdarg.h>
#include <string.h>

typedef struct {
  struct {
    int * _M_start;
    int * _M_finish;
    int * _M_end_of_storage;
  } _Vector_impl;
} std_vector;

typedef struct {
  char * _M_dataplus;
  size_t _M_len;
  union {
    size_t _M_capacity;
    char _M_data[8];
  } _M_data;
} std_string;

extern void *__gxx_personality_v0(void *);

int specialFilter(std_vector * v) {
  char buf[3];
  int i = 0;
  int * begin = v->_Vector_impl._M_start;
  int * end = v->_Vector_impl._M_finish;
  while (begin != end) {
    if (*begin > 10) {
      snprintf(buf, 3, "%d", *begin);
      int len = strlen(buf);
      if (len % 2 == 1) {
        i++;
      }
    }
    begin++;
  }
  return i;
}
int vsnprintf(char *str, size_t size, const char *format, va_list ap);

void free(void *ptr);
void *malloc(size_t size);
void *memcpy(void *dest, const void *src, size_t n);

size_t strlen(const char *str);

int main() {
  std_vector v;
  std_string s;

  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (specialFilter({5, -2, 1, -5}) == 0  );
    assert (specialFilter({15, -73, 14, -15}) == 1);
    assert (specialFilter({33, -2, -3, 45, 21, 109}) == 2);
    assert (specialFilter({43, -12, 93, 125, 121, 109}) == 4);
    assert (specialFilter({71, -2, -33, 75, 21, 19}) == 3);
    assert (specialFilter({1}) == 0              );
    assert (specialFilter({}) == 0                   );
}
