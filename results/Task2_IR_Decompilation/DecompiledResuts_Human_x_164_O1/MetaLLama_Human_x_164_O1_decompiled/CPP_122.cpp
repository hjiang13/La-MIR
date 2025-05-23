#include <stdio.h>
#include <stdint.h>

int add_elements(int* data, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        int value = data[i];
        if (value + 99 < 199) {
            result += value;
        }
    }
    return result;
}

int main() {
    // Example usage:
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    int result = add_elements(data, size);
    printf("%d\n", result);
    return 0;
}
