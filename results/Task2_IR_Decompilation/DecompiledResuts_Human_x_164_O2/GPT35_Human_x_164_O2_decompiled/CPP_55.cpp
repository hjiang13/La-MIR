```c
#include <stdio.h>

int f(int x) {
    int arr[1000];
    arr[0] = 0;
    arr[1] = 1;
    
    if (x < 2) {
        return arr[x];
    }
    
    for (int i = 2; i < x; i++) {
        arr[i] = 1;
    }
    
    for (int i = 3; i < x; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    
    return arr[x-1];
}

int main() {
    int result = f(10); // Change the argument to test different inputs
    printf("Result: %d\n", result);
    
    return 0;
}
```