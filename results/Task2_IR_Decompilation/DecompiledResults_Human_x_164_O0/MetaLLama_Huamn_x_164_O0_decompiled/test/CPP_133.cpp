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
#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_squares({1,2,3})==14);
    assert (sum_squares({1.0,2,3})==14);
    assert (sum_squares({1,3,5,7})==84);
    assert (sum_squares({1.4,4.2,0})==29);
    assert (sum_squares({-2.4,1,1})==6);
    assert (sum_squares({100,1,15,2})==10230);
    assert (sum_squares({10000,10000})==200000000);
    assert (sum_squares({-1.4,4.6,6.3})==75);
    assert (sum_squares({-1.4,17.9,18.9,19.9})==1086);
    assert (sum_squares({0})==0);
    assert (sum_squares({-1})==1);
    assert (sum_squares({-1,1,0})==2);
}
