#include <stdbool.h>

bool correct_bracketing(const char* str, int length) {
    int balance = 0;
    for (int i = 0; i < length; i++) {
        char c = str[i];
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return balance == 0;
}
