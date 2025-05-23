#include <stdio.h>

int greatest_common_divisor(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    int num1 = 15;
    int num2 = 25;
    int result = greatest_common_divisor(num1, num2);
    printf("Greatest common divisor of %d and %d is %d\n", num1, num2, result);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (greatest_common_divisor(3, 7) == 1);
     assert (greatest_common_divisor(10, 15) == 5);
      assert (greatest_common_divisor(49, 14) == 7);
     assert (greatest_common_divisor(144, 60) == 12);
}
