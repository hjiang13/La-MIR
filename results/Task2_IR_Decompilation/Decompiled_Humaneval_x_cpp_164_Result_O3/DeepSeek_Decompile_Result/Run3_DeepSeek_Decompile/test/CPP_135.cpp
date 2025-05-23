#include <vector>

int can_arrange(const std::vector<int>& vec) {
    if (vec.empty()) {
        return -1;
    }

    size_t size = vec.size();
    size_t max_offset = std::max((size + 1) / 2, 1UL);

    for (size_t i = 0; i < max_offset; ++i) {
        if (vec[i] > i + 1) {
            return i + 1;
        }
    }

    return size;
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
