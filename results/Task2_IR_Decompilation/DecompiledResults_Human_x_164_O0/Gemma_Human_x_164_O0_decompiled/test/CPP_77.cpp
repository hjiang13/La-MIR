Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <stdbool.h>

bool iscube(int n) {
    int i = 0;
    while (true) {
        int cube = i * i * i;
        if (cube > abs(n)) {
            return false;
        }
        if (cube == abs(n)) {
            return true;
        }
        i++;
    }
}

int main() {
    // You can call the iscube function from here
    return 0;
}
```

Note that the generated C code only includes the `iscube` function, as the IR code only defines this function. I've also added a `main` function as an entry point, but it's empty and doesn't call the `iscube` function. You can modify the `main` function to test the `iscube` function as needed.
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
