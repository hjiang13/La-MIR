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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add({4, 88}) == 88);
    assert (add({4, 5, 6, 7, 2, 122}) == 122);
    assert (add({4, 0, 6, 7}) == 0);
    assert (add({4, 4, 6, 8}) == 12);
}
