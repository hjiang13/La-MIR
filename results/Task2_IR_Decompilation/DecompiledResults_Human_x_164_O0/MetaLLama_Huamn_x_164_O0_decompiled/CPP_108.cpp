Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int* data;
    int* end;
    int* capacity;
} vector_t;

int vector_size(vector_t* v) {
    return (v->end - v->data);
}

int* vector_at(vector_t* v, int index) {
    return (v->data + index);
}

int abs(int x) {
    return (x < 0) ? -x : x;
}

int count_nums(vector_t* v) {
    int count = 0;
    for (int i = 0; i < vector_size(v); i++) {
        if (vector_at(v, i)[0] > 0) {
            count++;
        } else {
            int num = abs(vector_at(v, i)[0]);
            int sum = 0;
            while (num >= 10) {
                sum += num % 10;
                num /= 10;
            }
            sum -= num;
            if (sum > 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Example usage:
    int data[] = {1, -12, 3, -45, 6};
    vector_t v;
    v.data = data;
    v.end = v.data + sizeof(data) / sizeof(data[0]);
    v.capacity = v.end;
    printf("%d\n", count_nums(&v));
    return 0;
}
```

Please note that I've assumed a simple vector structure to represent the data, as the IR code does not provide the exact implementation of the vector class. The generated C code may not be exactly what the original C++ code looked like, but it should be equivalent in terms of functionality. Also, I've added a `main` function to demonstrate the usage of the `count_nums` function.