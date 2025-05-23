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
