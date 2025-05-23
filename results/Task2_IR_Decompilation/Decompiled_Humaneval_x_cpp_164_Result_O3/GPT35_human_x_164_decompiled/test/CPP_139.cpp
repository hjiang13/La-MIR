```c
#include <stdio.h>

long special_factorial(int n) {
    if (n < 1) {
        return 1;
    }

    long a = 1;
    long b = 1;
    long c = 1;
    long d = 1;
    
    for (int i = 1; i <= n; i++) {
        a = b * a;
        b = c * a;
        c = d * b;
        d = (i + 1) * c;
    }

    return d;
}

int main() {
    int n = 10;
    long result = special_factorial(n);
    printf("Special factorial of %d is: %ld\n", n, result);
    
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
