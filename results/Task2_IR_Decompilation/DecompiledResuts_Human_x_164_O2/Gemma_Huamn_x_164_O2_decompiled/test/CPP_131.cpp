#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __va_list_tag {
  int gp_offset;
  int fp_offset;
  void *overflow_arg_area;
  void *reg_save_area;
} __va_list_tag;

typedef struct {
  union {
    char *_M_p;
    struct {
      char *_M_local_buf;
    } _M_local_buf_ptr;
  } _M_data;
  size_t _M_len;
  size_t _M_cap;
  struct {
    char *_M_p;
    size_t _M_len;
    size_t _M_cap;
  } _M_short;
  
} basic_string;

int digitsi(int n) {
  char buf[3];
  sprintf(buf, "%d", n);
  basic_string s;

  s._M_data._M_p = 0;
  s._M_len = 0;
  s._M_cap = 0;
  if (strlen(buf) > 0) {
    s._M_data._M_p = (char *)malloc(strlen(buf)+1);
    strcpy(s._M_data._M_p, buf);
    s._M_len = strlen(buf);
    s._M_cap = strlen(buf);
  }

  int result = 0;
  char *p = s._M_data._M_p;
  for (size_t i = 0; i < s._M_len; ++i) {
    if (*p % 2 == 1) {
      result += (*p - 48);
    }
    ++p;
  }
  free(s._M_data._M_p);
  return result;
}

int main() {
  int n = 123;
  int result = digitsi(n);
  printf("Result: %d\n", result);
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (digits(5) == 5);
    assert (digits(54) == 5);
    assert (digits(120) ==1);
    assert (digits(5014) == 5);
    assert (digits(98765) == 315);
    assert (digits(5576543) == 2625);
    assert (digits(2468) == 0);
}
