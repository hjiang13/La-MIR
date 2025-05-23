```c
#include <stdio.h>

int special_factorial(int n) {
    int i = 1;
    long long fact = 1;
    long long result = 1;

    for (i = 1; i <= n; i++) {
        fact *= i;
        result *= fact;
    }

    return result;
}

int main() {
    int input = 5;
    long long output = special_factorial(input);
    printf("Special factorial of %d is %lld\n", input, output);

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}
