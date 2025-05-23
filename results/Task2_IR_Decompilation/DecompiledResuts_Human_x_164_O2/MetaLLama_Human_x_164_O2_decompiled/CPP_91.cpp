#include <stdint.h>

typedef struct {
    char* data;
    int64_t length;
} string_t;

int32_t is_bored(string_t* s) {
    int64_t length = s->length;
    if (length == 0) return 0;

    char* data = s->data;
    int64_t mask = length & 1;
    if (length == 1) {
        if (mask) {
            char c = *data;
            if (c == 32) return 1;
        }
        return 0;
    }

    int64_t offset = 0;
    int32_t count = 0;
    int32_t ret = 0;
    char last = 1;
    int64_t remaining = length & -2;

    while (1) {
        char c = data[offset];
        if (c == 32) {
            ret += count;
        }
        char next = data[offset + 1];
        if (c == 73 && last) {
            ret += 1;
        }
        if (next == 73 && c == 32) {
            last = 1;
        } else {
            last = 0;
        }
        if (c == '.' || c == '?' || c == '!') {
            last = 1;
        }
        if (next == '.' || next == '?' || next == '!') {
            last = 1;
        }
        offset += 2;
        remaining -= 2;
        if (remaining == 0) break;
    }

    if (mask) {
        char c = data[offset];
        if (c == 32) return ret + 1;
    }
    return ret;
}
