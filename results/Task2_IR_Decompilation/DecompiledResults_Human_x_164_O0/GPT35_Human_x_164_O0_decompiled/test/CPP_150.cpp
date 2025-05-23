```c
#include <stdio.h>

int x_or_y(int x, int y, int i) {
    int a = x, b = y, c = i;
    char flag = 1;
    
    if (a < 2) {
        flag = 0;
    }
    
    int num = 2;
    
    while (1) {
        int mul_result = num * num;
        
        if (mul_result <= a) {
            int remainder = a % num;
            
            if (remainder == 0) {
                flag = 0;
            }
            
            num++;
        } else {
            break;
        }
    }
    
    if (flag) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int x = 10;
    int y = 20;
    int i = 30;
    
    int result = x_or_y(x, y, i);
    
    printf("Result: %d\n", result);
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (x_or_y(7, 34, 12) == 34);
    assert (x_or_y(15, 8, 5) == 5);
    assert (x_or_y(3, 33, 5212) == 33);
    assert (x_or_y(1259, 3, 52) == 3);
    assert (x_or_y(7919, -1, 12) == -1);
    assert (x_or_y(3609, 1245, 583) == 583);
    assert (x_or_y(91, 56, 129) == 129);
    assert (x_or_y(6, 34, 1234) == 1234);
    assert (x_or_y(1, 2, 0) == 0);
    assert (x_or_y(2, 2, 0) == 2);
}
