#include <vector>
#include <algorithm>

int next_smallest(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] != vec[i - 1]) {
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
