```cpp
#include <vector>
#include <algorithm>

int next_smallest(std::vector<int> &vec) {
    if (vec.empty()) {
        return -1;
    }

    std::sort(vec.begin(), vec.end());

    int smallest = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] > smallest) {
            return vec[i];
        }
    }

    return -1;
}

int main() {
    std::vector<int> vec = {5, 3, 7, 1, 9, 2};
    int result = next_smallest(vec);
    
    return 0;
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
