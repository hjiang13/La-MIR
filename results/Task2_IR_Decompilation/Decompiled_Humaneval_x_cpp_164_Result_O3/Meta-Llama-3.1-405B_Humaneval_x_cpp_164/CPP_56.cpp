#include <stdio.h>
#include <stdint.h>

typedef struct {
    char* ptr;
    int64_t length;
    union {
        int64_t capacity;
        char data[8];
    } anon;
} basic_string;

int correct_bracketing(basic_string* str) {
    if (str->length == 0) {
        return 1;
    }

    char* data = str->ptr;
    int64_t i = 0;
    int32_t balance = 0;

    do {
        char c = data[i];
        balance += (c == '<') ? 1 : (c == '>') ? -1 : 0;
        if (balance < 0) {
            return 0;
        }
        i++;
    } while (i < str->length);

    return balance == 0;
}
