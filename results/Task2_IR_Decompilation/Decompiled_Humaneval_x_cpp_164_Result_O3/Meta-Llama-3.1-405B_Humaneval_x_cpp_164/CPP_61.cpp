#include <stdbool.h>

bool correct_bracketing(const char* str, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
        }
        if (count < 0) {
            return false;
        }
    }
    return count == 0;
}
