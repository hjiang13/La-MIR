#include <stdint.h>
#include <string.h>

int can_arrange(int* data, int size) {
    int i;
    int result = -1;
    for (i = 0; i < size; i++) {
        if (i < data[i]) {
            result = i;
        }
    }
    return result;
}

int main() {
    // Call the can_arrange function with some sample data
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    int result = can_arrange(data, size);
    return 0;
}
