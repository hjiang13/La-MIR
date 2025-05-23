Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <string.h>

void encrypt(char* out, const char* in) {
    int len = strlen(in);
    int i;
    for (i = 0; i < len; i++) {
        char c = in[i] + 4 - 97;
        c = c % 26 + 97;
        char tmp[2];
        tmp[0] = c;
        tmp[1] = '\0';
        strcat(out, tmp);
    }
}

int main() {
    char out[256] = "";
    const char* in = "your_input_string";
    encrypt(out, in);
    printf("%s\n", out);
    return 0;
}
```

Please note that this C code assumes that the input string is null-terminated and that the output buffer is large enough to hold the encrypted string. Also, the `main` function is added for demonstration purposes and can be removed if not needed.