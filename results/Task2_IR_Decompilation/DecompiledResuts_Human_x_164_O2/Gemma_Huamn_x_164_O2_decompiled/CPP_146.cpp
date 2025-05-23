```c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
} vector;

int specialFilter(vector *v) {
    char str[3];
    int *p = v->data;
    int *end = v->data + v->size;
    int count = 0;

    while (p < end) {
        if (*p > 10) {
            sprintf(str, "%d", *p);
            if (str[0] % 2 == 1) {
                count++;
            }
        }
        p++;
    }

    return count;
}

int main() {
    vector v;

    v.data = (int *)malloc(sizeof(int) * 10);
    v.size = 10;
    for (int i = 0; i < v.size; i++) {
        v.data[i] = i;
    }
    int result = specialFilter(&v);
    printf("Result: %d\n", result);
    free(v.data);
    return 0;
}
```