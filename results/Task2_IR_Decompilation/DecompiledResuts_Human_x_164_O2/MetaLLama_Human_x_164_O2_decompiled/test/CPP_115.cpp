#include <stdio.h>
#include <stdint.h>

#define MAX_FILL 8

int max_fill(int** vec, int size, int fill_value) {
    int32_t max = 0;
    for (int i = 0; i < size; i++) {
        int32_t sum = 0;
        for (int j = 0; j < vec[i][1] - vec[i][0]; j++) {
            sum += vec[i][0][j];
        }
        if (sum > max) max = sum;
    }
    return max / fill_value;
}

int main() {
    // Initialize vectors
    int** vec = (int**)malloc(10 * sizeof(int*));
    for (int i = 0; i < 10; i++) {
        vec[i] = (int*)malloc(2 * sizeof(int));
        vec[i][0] = (int)malloc(100 * sizeof(int));
        vec[i][1] = vec[i][0] + 100;
        for (int j = 0; j < 100; j++) {
            vec[i][0][j] = j;
        }
    }

    int result = max_fill(vec, 10, MAX_FILL);
    printf("%d\n", result);

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (max_fill({{0,0,1,0}, {0,1,0,0}, {1,1,1,1}}, 1) == 6);
    assert (max_fill({{0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}}, 2) == 5);
    assert (max_fill({{0,0,0}, {0,0,0}}, 5) == 0);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 2) == 4);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 9) == 2);
}
