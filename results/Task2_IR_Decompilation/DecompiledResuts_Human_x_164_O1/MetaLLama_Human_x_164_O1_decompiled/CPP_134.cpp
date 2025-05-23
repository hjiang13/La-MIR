#include <stdint.h>

typedef struct {
    void* _Alloc_hider;
    int64_t _M_size;
    union {
        int64_t _M_capacity;
        char _M_data[8];
    } _M_data;
} basic_string;

int check_if_last_char_is_a_letter(basic_string* s) {
    if (s->_M_size == 0) {
        return 0;
    }
    char* data = (char*)s->_M_data._M_data;
    char last_char = data[s->_M_size - 1];
    if (last_char < 65) {
        return 0;
    }
    if (last_char > 90) {
        int shift = last_char - 91;
        int mask = 133143986239 >> shift;
        if ((mask & 1) != 0) {
            return 0;
        }
    }
    if (s->_M_size == 1) {
        return 1;
    }
    char second_last_char = data[s->_M_size - 2];
    if (second_last_char >= 65 && second_last_char <= 90) {
        return 1;
    }
    if (second_last_char >= 97 && second_last_char <= 122) {
        return 1;
    }
    return 0;
}
