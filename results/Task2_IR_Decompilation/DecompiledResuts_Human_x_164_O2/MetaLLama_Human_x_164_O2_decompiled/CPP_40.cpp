#include <stdbool.h>
#include <stdint.h>

bool triples_sum_to_zero(int* arr, int size) {
    bool result = false;
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    result = true;
                    goto end;
                }
            }
        }
    }
end:
    return result;
}
