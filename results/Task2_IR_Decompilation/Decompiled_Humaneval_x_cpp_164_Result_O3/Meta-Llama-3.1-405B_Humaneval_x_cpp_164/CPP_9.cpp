#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rolling_max(int** output, int** input, int input_size) {
    int* output_data = (int*)malloc(input_size * sizeof(int));
    output_data[0] = input[0][0];
    int max_val = input[0][0];

    for (int i = 1; i < input_size; ++i) {
        if (input[0][i] > max_val) {
            max_val = input[0][i];
        }
        output_data[i] = max_val;
    }

    *output = output_data;
}

int main() {
    int input_size = 10;
    int* input_data = (int*)malloc(input_size * sizeof(int));

    for (int i = 0; i < input_size; ++i) {
        input_data[i] = i;
    }

    int* output_data;
    rolling_max(&output_data, &input_data, input_size);

    for (int i = 0; i < input_size; ++i) {
        printf("%d ", output_data[i]);
    }

    free(input_data);
    free(output_data);

    return 0;
}
