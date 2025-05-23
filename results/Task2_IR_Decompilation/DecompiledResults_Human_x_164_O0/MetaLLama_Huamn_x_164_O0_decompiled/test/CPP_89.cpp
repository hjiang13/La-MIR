Based on the LLVM IR code provided, I will generate the equivalent C source code. 

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        c = (c + 4 - 97) % 26 + 97;
        printf("%c", c);
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    encrypt(str);
    return 0;
}
```

Note: The generated C code is a simplified version and may not be exactly equivalent to the LLVM IR code, but it achieves the same functionality. Also, the `encrypt` function in the C code takes a `char*` instead of a `std::string` as in the LLVM IR code, since `std::string` is a C++ class and not available in C. The `main` function is also added to provide a complete C program.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (encrypt("hi") == "lm");
    assert (encrypt("asdfghjkl") == "ewhjklnop");
    assert (encrypt("gf") == "kj");
    assert (encrypt("et") == "ix");
    assert (encrypt("faewfawefaewg")=="jeiajeaijeiak");
    assert (encrypt("hellomyfriend")=="lippsqcjvmirh");
    assert (encrypt("dxzdlmnilfuhmilufhlihufnmlimnufhlimnufhfucufh")=="hbdhpqrmpjylqmpyjlpmlyjrqpmqryjlpmqryjljygyjl");
    assert (encrypt("a")=="e");
}
