#include <stdio.h>
#include <string.h>

typedef struct {
    char* _M_p;
    unsigned long long _M_string_length;
} std_string;

int is_nested(std_string* s) {
    if (s->_M_string_length == 0) {
        return 0;
    }

    char* p = s->_M_p;
    int balance = 0;
    int max_balance = 0;

    for (unsigned long long i = 0; i < s->_M_string_length; i++) {
        char c = p[i];
        if (c == '[') {
            balance++;
            max_balance = max_balance > balance ? max_balance : balance;
        } else if (c == ']') {
            balance--;
        }
    }

    return s->_M_string_length > i;
}
