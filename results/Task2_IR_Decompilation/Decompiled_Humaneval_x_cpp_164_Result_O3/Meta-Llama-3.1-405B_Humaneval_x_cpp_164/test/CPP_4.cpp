#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float mean_absolute_deviation(float* data, int size) {
    float sum = 0.0f;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    float mean = sum / size;

    float sum_abs_diff = 0.0f;
    for (int i = 0; i < size; i++) {
        sum_abs_diff += fabs(data[i] - mean);
    }
    return sum_abs_diff / size;
}

int main() {
    // example usage
    float data[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    int size = sizeof(data) / sizeof(data[0]);
    float result = mean_absolute_deviation(data, size);
    printf("Mean Absolute Deviation: %f\n", result);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}