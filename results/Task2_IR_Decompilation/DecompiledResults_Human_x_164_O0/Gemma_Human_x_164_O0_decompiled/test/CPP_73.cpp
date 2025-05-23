Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} vector;

int vector_size(vector* v) {
    return v->size;
}

int* vector_at(vector* v, int index) {
    return &v->data[index];
}

int smallest_change(vector* v) {
    int count = 0;
    for (int i = 0; i < vector_size(v) - 1; i++) {
        if (v->data[i] != v->data[i + 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    // Example usage:
    vector v;
    v.size = 10;
    v.capacity = 10;
    v.data = (int*)malloc(v.capacity * sizeof(int));
    for (int i = 0; i < v.size; i++) {
        v.data[i] = i;
    }
    printf("%d\n", smallest_change(&v));
    free(v.data);
    return 0;
}
```

Please note that the generated C code is a direct translation of the provided LLVM IR code. It may not be the most efficient or idiomatic C code, but it should produce the same results as the original IR code. Also, I've added a `main` function to demonstrate the usage of the generated code.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (smallest_change({1,2,3,5,4,7,9,6}) == 4);
    assert (smallest_change({1, 2, 3, 4, 3, 2, 2}) == 1);
    assert (smallest_change({1, 4, 2}) == 1);
    assert (smallest_change({1, 4, 4, 2}) == 1);
    assert (smallest_change({1, 2, 3, 2, 1}) == 0);
    assert (smallest_change({3, 1, 1, 3}) == 0);
    assert (smallest_change({1}) == 0);
    assert (smallest_change({0, 1}) == 1);
}
