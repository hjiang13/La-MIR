Here is the C source code corresponding to the provided LLVM IR code:

```c
long long special_factorial(int n) {
    long long _3 = 1;
    long long _4 = 1;
    int _5 = 1;
    while (_5 <= n) {
        long long _14 = _3 * (long long)_5;
        _3 = _14;
        long long _17 = _4 * _3;
        _4 = _17;
        _5 = _5 + 1;
    }
    return _4;
}
```

Note that I have kept the variable names as close to the original IR code as possible, even though they are not very descriptive. In a real-world scenario, you would likely want to rename them to something more meaningful.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}
