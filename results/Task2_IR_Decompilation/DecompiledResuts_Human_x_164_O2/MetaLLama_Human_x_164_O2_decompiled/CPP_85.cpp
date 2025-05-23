#include <stdio.h>
#include <stdint.h>

int add(int* data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if ((data[i] & 1) == 0) {
            sum += data[i];
        }
    }
    return sum;
}

int main() {
    // Assume data is an array of integers and size is its length
    int data[] = { /* initialize with some values */ };
    int size = sizeof(data) / sizeof(data[0]);
    int result = add(data, size);
    return result;
}
