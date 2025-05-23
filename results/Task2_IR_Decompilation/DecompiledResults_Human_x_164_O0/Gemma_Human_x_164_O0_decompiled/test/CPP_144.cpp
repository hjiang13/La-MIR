Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* _M_p;
    unsigned long _M_string_length;
    unsigned long _M_capacity;
} string;

int atoi(const char *);

int simplify(string* str1, string* str2) {
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, i = 0;
    while (i < str1->_M_string_length) {
        if (str1->_M_p[i] == '/') {
            num1 = atoi(str1->_M_p);
            num2 = atoi(str1->_M_p + i + 1);
            break;
        }
        i++;
    }
    i = 0;
    while (i < str2->_M_string_length) {
        if (str2->_M_p[i] == '/') {
            num3 = atoi(str2->_M_p);
            num4 = atoi(str2->_M_p + i + 1);
            break;
        }
        i++;
    }
    return (num1 * num3) % (num2 * num4) == 0;
}
```

Please note that this C code is a direct translation of the provided LLVM IR code and might not be the most efficient or readable version. Additionally, some parts of the IR code (e.g., the `string` struct) had to be manually reconstructed, as they were not explicitly defined in the IR code.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (simplify("1/5", "5/1") == true);
    assert (simplify("1/6", "2/1") == false);
    assert (simplify("5/1", "3/1") == true);
    assert (simplify("7/10", "10/2") == false);
    assert (simplify("2/10", "50/10") == true);
    assert (simplify("7/2", "4/2") == true);
    assert (simplify("11/6", "6/1") == true);
    assert (simplify("2/3", "5/2") == false);
    assert (simplify("5/2", "3/5") == false);
    assert (simplify("2/4", "8/4") == true);
    assert (simplify("2/4", "4/2") == true);
    assert (simplify("1/5", "5/1") == true);
    assert (simplify("1/5", "1/5") == false);
}
