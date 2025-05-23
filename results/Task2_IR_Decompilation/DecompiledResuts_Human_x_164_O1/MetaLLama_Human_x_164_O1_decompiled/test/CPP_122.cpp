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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add_elements({1,-2,-3,41,57,76,87,88,99}, 3) == -4);
    assert (add_elements({111,121,3,4000,5,6}, 2) == 0);
    assert (add_elements({11,21,3,90,5,6,7,8,9}, 4) == 125);
    assert (add_elements({111,21,3,4000,5,6,7,8,9}, 4) == 24);
    assert (add_elements({1}, 1) == 1);
}
