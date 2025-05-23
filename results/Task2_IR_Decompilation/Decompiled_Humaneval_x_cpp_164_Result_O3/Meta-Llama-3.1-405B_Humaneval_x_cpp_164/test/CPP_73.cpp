#include <stdint.h>

int smallest_change(void* vector) {
    int32_t** data = *(int32_t**)((char*)vector + 16);
    int32_t** end = *(int32_t**)((char*)vector + 8);
    int64_t size = (int64_t)end - (int64_t)data;
    int64_t len = size >> 2;
    int64_t idx = -1;
    int32_t result = 0;

    while (idx < len - 2) {
        int32_t* current = data[idx + 1];
        int32_t* next = data[idx + 2];
        int32_t changed = *current != *next;
        result += changed;
        idx++;
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (smallest_change({1,2,3,5,4,7,9,6}) == 4);
    assert (smallest_change({1, 2, 3, 4, 3, 2, 2}) == 1);
    assert (smallest_change({1, 4, 2}) == 1);
    assert (smallest_change({1, 4, 4, 2}) == 1);
    assert (smallest_change({1, 2, 3, 2, 1}) == 0);
    assert (smallest_change({3, 1, 1, 3}) == 0);
    assert (smallest_change({1}) == 0);
    assert (smallest_change({0, 1}) == 1);
}
