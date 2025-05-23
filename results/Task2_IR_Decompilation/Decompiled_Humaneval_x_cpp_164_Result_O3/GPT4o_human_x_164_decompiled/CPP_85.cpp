```cpp
#include <vector>
#include <cstdint>

extern "C" int llvm_vector_reduce_add_v4i32(int32_t a[4]);

int add(std::vector<int> &vec) {
    int32_t *data = vec.data();
    int64_t size = vec.size();
    
    if (size <= 1) return 0;

    int64_t limit = size / 4 * 4;
    int32_t result[4] = {0, 0, 0, 0};
    
    for (int64_t i = 0; i < limit; i += 4) {
        result[0] += data[i];
        result[1] += data[i + 1];
        result[2] += data[i + 2];
        result[3] += data[i + 3];
    }

    int32_t final_result = llvm_vector_reduce_add_v4i32(result);

    for (int64_t i = limit; i < size; ++i) {
        final_result += data[i];
    }

    return final_result;
}
```