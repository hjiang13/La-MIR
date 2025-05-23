#include <stdbool.h>
#include <string.h>

bool prime_length(const char* str) {
    size_t length = strlen(str);
    if (length < 2) {
        return false;
    }
    if (length < 4) {
        return true;
    }
    for (size_t i = 2; ; ++i) {
        if (length % i == 0) {
            if (i * i > length) {
                return true;
            }
            return false;
        }
    }
}
