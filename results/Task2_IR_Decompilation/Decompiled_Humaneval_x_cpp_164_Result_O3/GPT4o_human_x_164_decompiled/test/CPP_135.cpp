#include <vector>
#include <cstdint>

int64_t llvm_umax(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

int can_arrange(std::vector<int> &v) {
    int32_t result = -1;
    int32_t size = v.size();
    if (size == 0) return result;

    int64_t start = 0;
    int64_t end = size - 1;

    while (true) {
        int32_t idx = start;
        int32_t val = v[idx];
        if (idx < val) {
            result = idx;
            start++;
        } else if (start >= size) {
            break;
        }
        
        if (end <= 0) {
            break;
        }
        end -= 4;
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (can_arrange({1,2,4,3,5})==3);
    assert (can_arrange({1,2,4,5})==-1);
    assert (can_arrange({1,4,2,5,6,7,8,9,10})==2);
    assert (can_arrange({4,8,5,7,3})==4);
    assert (can_arrange({})==-1);
}
