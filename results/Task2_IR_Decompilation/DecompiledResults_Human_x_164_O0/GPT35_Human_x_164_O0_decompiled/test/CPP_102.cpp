```c
#include <stdio.h>

int choose_num(int num1, int num2) {
    int result = 0;
    
    if (num2 < num1) {
        result = -1;
    } else {
        if (num2 == num1) {
            if (num2 % 2 == 1) {
                result = -1;
            }
        } else {
            if (num2 % 2 == 1) {
                result = num2 - 1;
            } else {
                result = num2;
            }
        }
    }
    
    return result;
}

int main() {
    int num1 = 5;
    int num2 = 7;
    
    int result = choose_num(num1, num2);
    
    printf("Result: %d\n", result);
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (choose_num(12, 15) == 14);
    assert (choose_num(13, 12) == -1);
    assert (choose_num(33, 12354) == 12354);
    assert (choose_num(5234, 5233) == -1);
    assert (choose_num(6, 29) == 28);
    assert (choose_num(27, 10) == -1);
    assert (choose_num(7, 7) == -1);
    assert (choose_num(546, 546) == 546);
}
