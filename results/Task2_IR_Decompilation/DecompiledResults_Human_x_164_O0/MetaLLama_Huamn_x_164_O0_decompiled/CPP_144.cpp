Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int simplify(const char* str1, const char* str2) {
    int i = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;

    while (i < strlen(str1)) {
        if (str1[i] == '/') {
            char substr[256];
            strncpy(substr, str1, i);
            substr[i] = '\0';
            num1 = atoi(substr);
            strcpy(substr, str1 + i + 1);
            num2 = atoi(substr);
        }
        i++;
    }

    i = 0;
    while (i < strlen(str2)) {
        if (str2[i] == '/') {
            char substr[256];
            strncpy(substr, str2, i);
            substr[i] = '\0';
            num3 = atoi(substr);
            strcpy(substr, str2 + i + 1);
            num4 = atoi(substr);
;        }
        i++;
    }

    if ((num1 * num3) % (num2 * num4) == 0) {
        return 1;
    } else {
        return 0;
    }
}
```

Note that I've made some assumptions about the input strings and the expected behavior of the function, as the IR code does not provide any explicit information about these aspects. The generated C code may need to be adjusted based on the actual requirements of the application.