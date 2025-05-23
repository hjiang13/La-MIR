```cpp
#include <vector>
#include <algorithm>

int max_fill(std::vector<std::vector<int>> vec, int val) {
    int max_count = 0;
    for (const auto& inner_vec : vec) {
        int count = std::count(inner_vec.begin(), inner_vec.end(), val);
        if (count > max_count) {
            max_count = count;
        }
    }
    return max_count;
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
