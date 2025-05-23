Here is the C source code generated from the provided LLVM IR code:

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encode_shift(char* str, char* result) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        c = (c + 5 - 97) % 26 + 97;
        result[i] = c;
    }
}

void decode_shift(char* str, char* result) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        c = (c + 21 - 97) % 26 + 97;
        result[i] = c;
    }
}

int main() {
    char str[100];
    char result[100];
    scanf("%s", str);
    encode_shift(str, result);
    printf("%s\n", result);
    decode_shift(result, str);
    printf("%s\n", str);
    return 0;
}
```

Note that the generated C code assumes that the input string only contains lowercase letters and does not handle any potential errors. Also, the `main` function is added to demonstrate the usage of the `encode_shift` and `decode_shift` functions.
#undef NDEBUG
#include<assert.h>
int main(){
    
    for (int i=0;i<100;i++)
    {
        int l=10+rand()%11;
        string str="";
        for (int j=0;j<l;j++)
        {
            char chr=97+rand()%26;
            str+=chr;
        }

        string encoded_str = encode_shift(str);
        assert (decode_shift(encoded_str) == str);
    }
}
