Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum_squares(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        float val = (float)arr[i];
        sum += (int)ceilf(val) * (int)ceilf(val);
    }
    return sum;
}

int main() {
    int size = 10;
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
    int result = sum_squares(arr, size);
    printf("%d\n", result);
    free(arr);
    return 0;
}
```

Please note that I had to make some assumptions about the input and output of the `sum_squares` function, as well as the `main` function, since they were not explicitly defined in the IR code. The generated C code may not be exactly what you had in mind, but it should be equivalent to the IR code provided.