```c
#include <stdio.h>

int sum_to_n(int n) {
    int temp1 = n + 1;
    int temp2 = temp1 * n;
    int result = temp2 / 2;
    return result;
}

int main() {
    int n = 5;
    int sum = sum_to_n(n);
    printf("Sum of numbers from 1 to %d is: %d\n", n, sum);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_to_n(1) == 1);
    assert (sum_to_n(6) == 21);
    assert (sum_to_n(11) == 66);
    assert (sum_to_n(30) == 465);
    assert (sum_to_n(100) == 5050);
}
