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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (valid_date("03-11-2000") == true);
    assert (valid_date("15-01-2012") == false);
    assert (valid_date("04-0-2040") == false);
    assert (valid_date("06-04-2020") == true);
    assert (valid_date("01-01-2007") == true);
    assert (valid_date("03-32-2011") == false);
    assert (valid_date("") == false);
    assert (valid_date("04-31-3000") == false);
    assert (valid_date("06-06-2005") == true);
    assert (valid_date("21-31-2000") == false);
    assert (valid_date("04-12-2003") == true);
    assert (valid_date("04122003") == false);
    assert (valid_date("20030412") == false);
    assert (valid_date("2003-04") == false);
    assert (valid_date("2003-04-12") == false);
    assert (valid_date("04-2003") == false);
}
