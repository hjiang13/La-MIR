```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

void count_up_to(std::vector<int>& vec, int limit) {
    if (limit > 2) {
        vec.clear();
        int num = 2;
        while (true) {
            int square = num * num;
            if (square > limit) {
                break;
            }
            vec.push_back(square);
            num++;
        }
    }
}

int main() {
    std::vector<int> result;
    count_up_to(result, 100);
    return 0;
}
```