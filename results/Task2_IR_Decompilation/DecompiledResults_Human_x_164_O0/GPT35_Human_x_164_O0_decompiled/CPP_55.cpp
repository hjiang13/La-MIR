```c
#include <stdio.h>

int f(int x) {
    int arr[1000];
    int i, sum = 0;
    
    arr[0] = 0;
    arr[1] = 1;
    
    for (i = 2; i <= x; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    return arr[x];
}

int main() {
    int result = f(10); // Change the argument to test different values
    printf("Result: %d\n", result);
    
    return 0;
}
```