#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned short i16;
typedef unsigned int i32;
typedef unsigned long long i64;

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    i64 _M_string_length;
    union {
        i64 _M_capacity;
        char _M_data[8];
    } _M_size;
} string;

int valid_date(string* date) {
    if (date->_M_string_length == 10) {
        char* str = date->_M_dataplus._M_p;
        if (str[0] == '-' || str[1] == '-') {
            return false;
        }
        for (int i = 0; i < 10; i++) {
            if (str[i] < '0' || str[i] > '9') {
                return false;
            }
        }
        i64 day = strtol(str, NULL, 10);
        if (day < 1 || day > 31) {
            return false;
        }
        str += 3;
        i64 month = strtol(str, NULL, 10);
        if (month < 1 || month > 12) {
            return false;
        }
        str += 3;
        i64 year = strtol(str, NULL, 10);
        if (year < 1 || year > 9999) {
            return false;
        }
        if ((month == 2 && day > 28) || (month == 4 && day > 30) || (month == 6 && day > 30) || (month == 9 && day > 30) || (month == 11 && day > 30)) {
            return false;
        }
        return true;
    }
    return false;
}
