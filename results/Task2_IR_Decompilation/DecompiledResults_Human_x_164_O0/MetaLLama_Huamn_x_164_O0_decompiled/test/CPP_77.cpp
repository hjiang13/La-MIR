Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
#include <stdio.h>

int abs(int x) {
    return x < 0 ? -x : x;
}

int iscuber(int x) {
    int i = 0;
    while (1) {
        long long cube = (long long)i * i * i;
        if (cube <= abs(x)) {
            if (cube == abs(x)) {
                return 1;
            }
            i++;
        } else {
            return 0;
        }
    }
}
```

Please note that I've used the `long long` type to avoid integer overflow when calculating the cube. Also, the `abs` function is implemented as a simple ternary expression. Let me know if you need any further assistance!
#undef NDEBUG
#include<assert.h>
int main(){
    assert (iscuber(1) == true);
    assert (iscuber(2) == false);
    assert (iscuber(-1) == true);
    assert (iscuber(64) == true);
    assert (iscuber(180) == false);
    assert (iscuber(1000) == true);
    assert (iscuber(0) == true);
    assert (iscuber(1729) == false);
}
