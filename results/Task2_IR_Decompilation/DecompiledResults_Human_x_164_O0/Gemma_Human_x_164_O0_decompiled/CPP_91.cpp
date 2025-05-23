Here's the generated C source code based on the given LLVM IR code:

```c
#include <stdio.h>
#include <string.h>

int is_bored(char *s) {
    int count = 0;
    int flag = 0;
    int i = 0;
    int state = 1;

    while (i < strlen(s)) {
        if (s[i] == ' ') {
            if (flag) {
                count++;
                flag = 0;
            }
        } else if (s[i] == 'I') {
            if (state) {
                flag = 1;
            }
        } else if (s[i] != ' ') {
            state = 0;
        }
        if (s[i] == '.' || s[i] == '?' || s[i] == '!') {
            state = 1;
        }
        i++;
    }
    return count;
}
```
Please note that this generated code may not be exactly the original C++ code used to generate the LLVM IR, as the IR is a platform-independent representation and some information about the original code may have been lost. However, the generated C code should produce the same output as the original code when given the same input. Also note that this code has been written in C, but the original code was likely in C++.