#include <vector>

extern "C" {
    int llvm_vector_reduce_add_v4i32(int32_t*);

    bool move_one_ball(std::vector<int>& vec) {
        int32_t* data = vec.data();
        int64_t size = vec.size();
        if (size == 0) return false;
        
        int64_t blocks = size / 4;
        int64_t remainder = size % 4;
        
        int32_t acc[4] = {0, 0, 0, 0};
        for (int64_t i = 0; i < blocks; ++i) {
            int32_t* block = data + i * 4;
            for (int j = 0; j < 4; ++j) {
                acc[j] += block[j];
            }
        }

        for (int64_t i = 0; i < remainder; ++i) {
            acc[i] += data[blocks * 4 + i];
        }

        return llvm_vector_reduce_add_v4i32(acc) > 0;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (move_one_ball({3, 4, 5, 1, 2})==true);
    assert (move_one_ball({3, 5, 10, 1, 2})==true);
    assert (move_one_ball({4, 3, 1, 2})==false);
    assert (move_one_ball({3, 5, 4, 1, 2})==false);
    assert (move_one_ball({})==true);
}
