Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>
#include <string.h>

void encode_shift(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        c += 5;
        if (c > 'z') {
            c -= 26;
        }
        printf("%c", c);
    }
    printf("\n");
}

void decode_shift(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        c -= 5;
        if (c < 'a') {
            c += 26;
        }
        printf("%c", c);
    }
    printf("\n");
}

int main() {
    char str[] = "hello";
    encode_shift(str);
    decode_shift(str);
    return 0;
}
```

Please note that the generated C code is a simplified version and may not cover all the nuances of the original LLVM IR code. Additionally, the `main` function is added to demonstrate the usage of the `encode_shift` and `decode_shift` functions.