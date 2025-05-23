#include <stdio.h>
#include <string.h>

typedef struct {
    char* _M_p;
    unsigned long long _M_string_length;
    unsigned long long _M_allocated_capacity;
} basic_string;

int is_nested(basic_string* str) {
    if (str->_M_string_length == 0) {
        return 0;
    }

    char* ptr = str->_M_p;
    unsigned long long i = 0;
    int nesting_level = 0;
    int max_nesting_level = 0;

    while (i < str->_M_string_length) {
        char c = *ptr;
        if (c == '[') {
            nesting_level++;
            if (nesting_level > max_nesting_level) {
                max_nesting_level = nesting_level;
            }
        } else if (c == ']') {
            nesting_level--;
        }
        ptr++;
        i++;
    }

    return max_nesting_level > 1;
}
