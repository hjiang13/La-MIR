#include <stdint.h>

typedef struct {
    void* _Alloc_hider;
    int64_t _M_string_length;
    union {
        int64_t _M_capacity;
        char _M_data[8];
    } _M_data_and_capacity;
} std_string;

int32_t strlen_std_string(std_string* s) {
    return (int32_t)s->_M_string_length;
}
