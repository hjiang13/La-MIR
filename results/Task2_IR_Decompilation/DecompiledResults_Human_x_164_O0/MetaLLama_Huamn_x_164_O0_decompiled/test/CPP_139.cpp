Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
long long special_factorial(int n) {
    long long result = 1;
    long long temp = 1;
    int i = 1;
    while (i <= n) {
        temp = temp * i;
        result = result * temp;
        i = i + 1;
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}
