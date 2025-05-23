Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_xor(char *s1, char *s2, char *result) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = 0;
    int flag = 0;

    while (i < len1 && i < len2) {
        if (s1[i] == s2[i]) {
            result[i] = '0';
        } else {
            result[i] = '1';
            flag = 1;
        }
        i++;
    }

    if (flag == 0) {
        if (len1 > len2) {
            while (i < len1) {
                result[i] = s1[i];
                i++;
            }
        } else if (len2 > len1) {
            while (i < len2) {
                result[i] = s2[i];
                i++;
            }
        }
    }

    result[i] = '\0';
}
```

Note that I've assumed that the `string_xor` function takes three `char*` arguments: `s1`, `s2`, and `result`. The `result` argument is assumed to be a buffer large enough to hold the resulting string. The function performs a bitwise XOR operation on the input strings and stores the result in the `result` buffer. If the input strings are of different lengths, the function appends the remaining characters from the longer string to the result.