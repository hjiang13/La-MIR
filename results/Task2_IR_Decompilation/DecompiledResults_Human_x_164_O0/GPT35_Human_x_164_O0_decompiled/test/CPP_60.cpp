```c
#include <stdio.h>

int sum_to_n(int num) {
    int temp = num;
    temp = temp * (temp + 1) / 2;
    return temp;
}

int main() {
    int num = 10;
    int result = sum_to_n(num);
    printf("Sum of numbers from 1 to %d is: %d\n", num, result);
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
