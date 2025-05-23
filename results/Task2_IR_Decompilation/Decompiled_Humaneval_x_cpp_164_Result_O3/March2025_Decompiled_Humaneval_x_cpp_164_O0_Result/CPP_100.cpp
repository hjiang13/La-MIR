```cpp
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

void make_a_pile(std::vector<int>& vec, int n) {
    std::vector<int> temp = {n};
    vec = std::vector<int>(temp.begin(), temp.end());
    for (int i = 1; i < n; ++i) {
        int last = vec.back();
        vec.push_back(last + 2);
    }
}

int main() {
    std::vector<int> vec;
    make_a_pile(vec, 10);
    return 0;
}
```