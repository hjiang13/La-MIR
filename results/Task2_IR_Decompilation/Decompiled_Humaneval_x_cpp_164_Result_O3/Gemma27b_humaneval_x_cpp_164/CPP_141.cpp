```c
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct basic_string {
    union {
        struct {
            char *data;
            uint64_t size;
        } _Alloc_hider;
        uint64_t _Data;
    } _M_impl;
};

void file_name_check(struct basic_string *result, const struct basic_string *file_name) {
    uint64_t size = file_name->_M_impl._Alloc_hider.size;
    if (size < 5) {
        result->_M_impl._Alloc_hider.data = (char *)&result->_M_impl._Data;
        *((uint16_t *)result->_M_impl._Alloc_hider.data) = 28494;
        result->_M_impl._Alloc_hider.size = 2;
        result->_M_impl._Alloc_hider.data[2] = 0;
        return;
    }
    const char *data = file_name->_M_impl._Alloc_hider.data;
    char first_char = *data;
    if (first_char < 65) {
        switch (first_char) {
        case 127:
        case 126:
        case 125:
        case 124:
        case 123:
        case 96: