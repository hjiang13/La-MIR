#include <vector>
#include <algorithm>

extern "C" {
    int llvm_umax_i64(int64_t a, int64_t b) {
        return std::max(a, b);
    }

    int vector_reduce_add_v4i32(int32_t* data) {
        return data[0] + data[1] + data[2] + data[3];
    }

    int max_fill(std::vector<std::vector<int>> &vec, int size) {
        auto &data = vec[0];
        auto &inner_data = vec[1];

        if (&data == &inner_data) {
            return 0;
        }

        int64_t difference = reinterpret_cast<int64_t>(&data) - reinterpret_cast<int64_t>(&inner_data);
        if (difference == 0) {
            return 0;
        }

        int64_t count = difference / 24;
        count = llvm_umax_i64(count, 1);
        int64_t idx = 0;
        int32_t sum = 0;

        while (idx < count) {
            int32_t* ptr1 = inner_data.data() + idx;
            int32_t* ptr2 = data.data() + idx;

            if (ptr1 == ptr2) {
                idx++;
                continue;
            }

            int64_t shift = difference >> 2;
            shift = llvm_umax_i64(shift, 1);
            int64_t threshold = shift < 8 ? 8 : shift;

            if (threshold < 24) {
                for (int64_t i = 0; i < threshold; i += 8) {
                    int32_t v1[4] = { ptr1[i], ptr1[i + 1], ptr1[i + 2], ptr1[i + 3] };
                    int32_t v2[4] = { data[i], data[i + 1], data[i + 2], data[i + 3] };
                    sum += vector_reduce_add_v4i32(v1) + vector_reduce_add_v4i32(v2);
                }
            }
            idx++;
        }
        return sum;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (max_fill({{0,0,1,0}, {0,1,0,0}, {1,1,1,1}}, 1) == 6);
    assert (max_fill({{0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}}, 2) == 5);
    assert (max_fill({{0,0,0}, {0,0,0}}, 5) == 0);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 2) == 4);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 9) == 2);
}
