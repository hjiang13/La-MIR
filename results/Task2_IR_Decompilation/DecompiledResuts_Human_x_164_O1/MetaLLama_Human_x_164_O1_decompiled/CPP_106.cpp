#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    int* data;
    int* end;
    int* capacity;
} Vector;

void vector_realloc_insert(Vector* vec, int* p, int x) {
    int new_size = (vec->end - vec->data) + 1;
    if (new_size > (vec->capacity - vec->data)) {
        int new_capacity = (new_size * 2);
        int* new_data = (int*)malloc(new_capacity * sizeof(int));
        if (new_data == NULL) {
            exit(1);
        }
        memcpy(new_data, vec->data, (vec->end - vec->data) * sizeof(int));
        free(vec->data);
        vec->data = new_data;
        vec->capacity = vec->data + new_capacity;
    }
    memmove(vec->data + (p - vec->data) + 1, p, (vec->end - p) * sizeof(int));
    *(p) = x;
    vec->end++;
}

void f(Vector* vec, int n) {
    int i;
    int j;
    int* p;
    vector_realloc_insert(vec, vec->data, 0);
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            p = vec->data + (vec->end - vec->data);
            vector_realloc_insert(vec, p, i);
        } else {
            p = vec->data;
            vector_realloc_insert(vec, p, i);
        }
    }
}

int main() {
    Vector vec;
    vec.data = NULL;
    vec.end = NULL;
    vec.capacity = NULL;
    f(&vec, 10);
    return 0;
}
