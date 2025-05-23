#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* ptr;
    long size;
} string;

int valid_date(string* date) {
    if (date->size == 10) {
        if (date->ptr[0] - '0' > 9) return 0;
        if (date->ptr[1] - '0' > 9) return 0;
        if (date->ptr[2] != '-') return 0;
        if (date->ptr[3] - '0' > 9) return 0;
        if (date->ptr[4] - '0' > 9) return 0;
        if (date->ptr[5] != '-') return 0;
        if (date->ptr[6] - '0' > 9) return 0;
        if (date->ptr[7] - '0' > 9) return 0;
        if (date->ptr[8] - '0' > 9) return 0;
        if (date->ptr[9] - '0' > 9) return 0;

        int day = (date->ptr[0] - '0') * 10 + (date->ptr[1] - '0');
        int month = (date->ptr[3] - '0') * 10 + (date->ptr[4] - '0');
        int year = (date->ptr[6] - '0') * 100 + (date->ptr[7] - '0') * 10 + (date->ptr[8] - '0') * 1;

        if (day < 1 || day > 31) return 0;
        if (month < 1 || month > 12) return 0;
        if (year < 1) return 0;

        if (month == 2) {
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                if (day > 29) return 0;
            } else {
                if (day > 28) return 0;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) return 0;
        }
    } else {
        return 0;
    }
    return 1;
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
