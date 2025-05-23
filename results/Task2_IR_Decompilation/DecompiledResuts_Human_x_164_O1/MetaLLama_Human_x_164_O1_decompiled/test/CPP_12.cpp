#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    size_t _M_string_length;
    union {
        size_t _M_capacity;
        char _M_data;
    } _M_data;
} string;

typedef struct {
    string* _M_impl;
} vector;

void longest(vector* vec, string* str) {
    string* begin = vec->_M_impl;
    string* end = vec->_M_impl + (vec->_M_impl->_M_string_length >> 5);
    string* max_str = begin;
    size_t max_len = 0;

    for (string* it = begin; it != end; ++it) {
        if (it->_M_string_length > max_len) {
            max_len = it->_M_string_length;
            max_str = it;
        }
    }

    str->_M_string_length = max_len;
    if (str->_M_dataplus._M_p != NULL) {
        free(str->_M_dataplus._M_p);
    }
    str->_M_dataplus._M_p = (char*)malloc(max_len + 1);
    strcpy(str->_M_dataplus._M_p, max_str->_M_dataplus._M_p);
}

int main() {
    vector vec;
    string str;
    longest(&vec, &str);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
