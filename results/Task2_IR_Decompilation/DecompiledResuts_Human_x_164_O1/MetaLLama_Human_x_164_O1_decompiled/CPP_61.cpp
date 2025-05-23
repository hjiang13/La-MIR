#include <stdint.h>

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    uint64_t _M_string_length;
    uint64_t _M_capacity;
} basic_string;

int correct_bracketing(basic_string* s) {
    uint64_t length = s->_M_string_length;
    if (length == 0) return 0;

    char* data = s->_M_dataplus._M_p;
    int bracket_count = 0;
    uint64_t i = 0;
    do {
        char c = data[i];
        if (c == '(') bracket_count++;
        else if (c == ')') bracket_count--;
        if (bracket_count < 0) return 0;
        i++;
    } while (i < length);

    return bracket_count == 0;
}
