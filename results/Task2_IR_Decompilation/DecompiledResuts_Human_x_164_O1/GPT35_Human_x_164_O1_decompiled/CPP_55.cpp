```c
#include <stdio.h>

int f(int x) {
    int arr[1000] = {0};
    
    if (x < 2) {
        return arr[x];
    } else {
        for (int i = 2; i <= x; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[x];
    }
}

int main() {
    int result = f(10);
    printf("Result: %d\n", result);
    return 0;
}
```