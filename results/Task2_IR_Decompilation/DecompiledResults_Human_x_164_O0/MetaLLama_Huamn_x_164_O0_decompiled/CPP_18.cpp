Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <string.h>

int how_many_times(const char* s1, const char* s2) {
    int count = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 == 0) return 0;

    for (int i = 0; i <= len1 - len2; i++) {
        char* substr = (char*)malloc((len2 + 1) * sizeof(char));
        strncpy(substr, s1 + i, len2);
        substr[len2] = '\0';

        if (strcmp(substr, s2) == 0) {
            count++;
        }
        free(substr);
    }

    return count;
}
```

Please note that this C code assumes that the input strings `s1` and `s2` are null-terminated. The `how_many_times` function returns the number of times `s2` appears as a substring in `s1`.