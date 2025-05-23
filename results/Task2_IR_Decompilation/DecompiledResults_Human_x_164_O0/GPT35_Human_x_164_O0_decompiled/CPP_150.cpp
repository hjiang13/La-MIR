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
```