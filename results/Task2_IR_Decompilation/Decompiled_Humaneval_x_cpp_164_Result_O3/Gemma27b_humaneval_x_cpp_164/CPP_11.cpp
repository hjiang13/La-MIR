```c
#include <stddef.h>
#include <stdint.h>

typedef struct {
  char* _alloc_hider;
  uint64_t _M_length;
  union {
    uint64_t _M_rep;
    char _M_buffer[8];
  };
} basic_string;

void string_xor(basic_string* __dest, const basic_string* __lhs, const basic_string* __rhs) {
  basic_string* __temp = __dest;
  __temp->_M_rep = __temp->_M_buffer;
  char* __ptr = (char*)__temp;
  basic_string* __dest_ptr = (basic_string*)__ptr;
  __dest_ptr->_M_length = 0;
  __ptr[0] = 0;
  uint64_t __lhs_len = __lhs->_M_length;
  uint64_t __rhs_len = __rhs->_M_length;
  char* __lhs_ptr = __lhs->_alloc_hider;
  char* __rhs_ptr = __rhs->_alloc_hider;
  char* __dest_data = __dest_ptr->_alloc_hider;
  if (__lhs_len == 0) {
    return;
  }
  uint64_t i = 0;
  while (i < __rhs_len) {
    if (__lhs_ptr[i] == __rhs_ptr[i]) {
      if (__dest_ptr->_M_length + 1 > 15) {
        (void)0;
      }
      __dest_data[__dest_ptr->_M_length] = 48;
      __dest_ptr->_M_length += 1;
      __dest_data[__dest_ptr->_M_length] = 0;
    }
    i++;
    if (i >= __lhs_len) {
      break;
    }
  }
}


```