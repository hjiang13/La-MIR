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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (specialFilter({5, -2, 1, -5}) == 0  );
    assert (specialFilter({15, -73, 14, -15}) == 1);
    assert (specialFilter({33, -2, -3, 45, 21, 109}) == 2);
    assert (specialFilter({43, -12, 93, 125, 121, 109}) == 4);
    assert (specialFilter({71, -2, -33, 75, 21, 19}) == 3);
    assert (specialFilter({1}) == 0              );
    assert (specialFilter({}) == 0                   );
}
