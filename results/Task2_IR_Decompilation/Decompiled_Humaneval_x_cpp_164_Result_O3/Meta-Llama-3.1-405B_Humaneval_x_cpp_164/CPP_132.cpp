#include <stdbool.h>
#include <stdint.h>

struct _Alloc_hider {
    char* ptr;
};

struct basic_string {
    struct _Alloc_hider _Alloc_hider;
    int64_t length;
    union {
        int64_t sso_length;
        char sso_buffer[8];
    } buffer;
};

bool is_nested(const struct basic_string* s) {
    if (s->length == 0) return false;

    int32_t nesting_level = 0;
    int32_t max_nesting_level = 0;
    for (int64_t i = 0; i < s->length; i++) {
        char c = s->_Alloc_hider.ptr[i];
        if (c == '[') nesting_level++;
        if (c == ']') nesting_level--;
        if (nesting_level > max_nesting_level) max_nesting_level = nesting_level;
    }

    return s->length > max_nesting_level;
}
