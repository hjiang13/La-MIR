Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <string.h>

int digitSum(const char *str) {
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            sum += str[i];
        }
    }
    return sum;
}
```

Note that the generated C code assumes that the input string only contains ASCII characters. The LLVM IR code seems to be checking for uppercase letters only, so I've kept that condition in the C code as well. If you need to handle other character ranges or non-ASCII characters, you may need to modify the code accordingly.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (digitSum("") == 0);
    assert (digitSum("abAB") == 131);
    assert (digitSum("abcCd") == 67);
    assert (digitSum("helloE") == 69);
    assert (digitSum("woArBld") == 131);
    assert (digitSum("aAaaaXa") == 153);
    assert (digitSum(" How are yOu?") == 151);
    assert (digitSum("You arE Very Smart") == 327);
}
