#include <stdlib.h>
#include <string.h>

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    long _M_string_length;
    char _M_local_buf[16];
} basic_string;

typedef struct {
    char _M_x;
} allocator;

extern void __throw_out_of_range_fmt(const char*, ...);
extern int __gxx_personality_v0(...);
extern void _ZdlPv(void*);
extern int _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareEPKc(basic_string*, const char*);

void _Z15file_name_checkNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(basic_string* noalias sret, basic_string* nocapture readonly str) {
    basic_string tmp;
    allocator alloc;

    if (str->_M_string_length < 5) {
        sret->_M_dataplus._M_p = "No";
        sret->_M_string_length = 2;
        return;
    }

    switch (str->_M_dataplus._M_p[0]) {
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
        case 96:
        case 123:
        case 124:
        case 125:
        case 126:
        case 127:
        {
            sret->_M_dataplus._M_p = "No";
            sret->_M_string_length = 2;
            return;
        }
        default:
            break;
    }

    tmp._M_dataplus._M_p = &str->_M_dataplus._M_p[str->_M_string_length - 4];

    if (str->_M_string_length < 4) {
        __throw_out_of_range_fmt("%s: __pos (which is %zu) > this->size() (which is %zu)", "_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEmm", str->_M_string_length - 4, str->_M_string_length);
    }

    if (strcmp(tmp._M_dataplus._M_p, ".txt") == 0 || strcmp(tmp._M_dataplus._M_p, ".exe") == 0 || strcmp(tmp._M_dataplus._M_p, ".dll") == 0) {
        sret->_M_dataplus._M_p = "No";
        sret->_M_string_length = 2;
        return;
    }

    int dot_cnt = 0;
    int digit_cnt = 0;

    for (long i = 0; i < str->_M_string_length; i++) {
        char c = str->_M_dataplus._M_p[i];
        if (c >= '0' && c <= '9') {
            digit_cnt++;
        } else if (c == '.') {
            dot_cnt++;
        }
    }

    if (digit_cnt > 3 || dot_cnt != 1) {
        sret->_M_dataplus._M_p = "No";
        sret->_M_string_length = 2;
    } else {
        sret->_M_dataplus._M_p = "Yes";
        sret->_M_string_length = 3;
    }

    return;
}
