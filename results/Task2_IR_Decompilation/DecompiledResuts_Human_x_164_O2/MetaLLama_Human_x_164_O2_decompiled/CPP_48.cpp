#include <string.h>
#include <stdlib.h>

typedef struct {
    char* _M_p;
    unsigned long _M_n;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    unsigned long _M_string_length;
    char _M_local_buf[16];
} __cxx11_basic_string;

int bcmp(const void* s1, const void* s2, size_t n) {
    return memcmp(s1, s2, n);
}

void* _ZdlPv(void* p) {
    return free(p);
}

int is_palindrome(__cxx11_basic_string* s) {
    unsigned long _M_n = s->_M_dataplus._M_n;
    char* _M_p = s->_M_dataplus._M_p;

    if (_M_n > 15) {
        char* _M_local_buf = s->_M_local_buf;
        __cxx11_basic_string* _M_string = malloc(sizeof(__cxx11_basic_string));

        _M_string->_M_dataplus._M_p = _M_local_buf;
        _M_string->_M_string_length = _M_n;

        unsigned long _M_len = _M_n;
        unsigned long _M_half_len = _M_len / 2;

        char* _M_first = _M_local_buf;
        char* _M_last = _M_p + _M_n - 1;

        while (_M_first < _M_last) {
            char _M_tmp = *_M_first;
            *_M_first = *_M_last;
            *_M_last = _M_tmp;

            _M_first++;
            _M_last--;
        }

        s->_M_dataplus._M_p = _M_local_buf;
    } else {
        char* _M_first = _M_p;
        char* _M_last = _M_p + _M_n - 1;

        while (_M_first < _M_last) {
            char _M_tmp = *_M_first;
            *_M_first = *_M_last;
            *_M_last = _M_tmp;

            _M_first++;
            _M_last--;
        }
    }

    char* _M_begin = s->_M_dataplus._M_p;
    char* _M_rbegin = _M_p;

    if (bcmp(_M_begin, _M_rbegin, _M_n) == 0) {
        return 1;
    } else {
        return 0;
    }
}
