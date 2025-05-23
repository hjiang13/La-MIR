#include <stdbool.h>
#include <stdint.h>

bool correct_bracketing(const char* s, size_t len) {
    if (len == 0) {
        return true;
    }

    int balance = 0;
    for (size_t i = 0; i < len; i++) {
        if (s[i] == '<') {
            balance++;
        } else if (s[i] == '>') {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }

    return balance == 0;
}
