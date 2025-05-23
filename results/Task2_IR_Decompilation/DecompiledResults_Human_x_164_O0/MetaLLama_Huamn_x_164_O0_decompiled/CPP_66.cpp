Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdint.h>

int digitSum(char* s) {
    int sum = 0;
    int i = 0;
    while (i < strlen(s)) {
        if (s[i] >= 65 && s[i] <= 90) {
            sum += s[i];
        }
        i++;
    }
    return sum;
}
```

Please note that the generated C code assumes that the input string `s` is a null-terminated string, and the `strlen` function is used to get the length of the string. If the input string is not null-terminated, you may need to modify the code to handle the length differently.