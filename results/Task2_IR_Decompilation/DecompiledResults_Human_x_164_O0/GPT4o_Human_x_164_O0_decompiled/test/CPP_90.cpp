#include <vector>
#include <algorithm>

int next_smallest(std::vector<int>& vec) {
    int* begin = vec.data();
    int* end = begin + vec.size();
    std::sort(begin, end);
    
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] != vec[vec.size() - 1 - i]) {
            return vec[i];
        }
    }
    return -1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (next_smallest({1, 2, 3, 4, 5}) == 2);
    assert (next_smallest({5, 1, 4, 3, 2}) == 2);
    assert (next_smallest({}) == -1);
    assert (next_smallest({1, 1}) == -1);
    assert (next_smallest({1,1,1,1,0}) == 1);
    assert (next_smallest({-35, 34, 12, -45}) == -35);
}
