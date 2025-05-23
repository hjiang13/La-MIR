```cpp
#include <vector>
#include <stdexcept>

void count_up_to(std::vector<int>& vec, int n) {
    int count = 0;
    for (count = 0; count < n; ++count) {
        if (count >= 2) {
            int* data = vec.data();
            if (data == nullptr) {
                vec.push_back(count);
            } else {
                int value = data[count];
                if (value * value > count) {
                    vec.push_back(value);
                }
            }
        }
    }
}

int main() {
    std::vector<int> vec;
    count_up_to(vec, 10);
    return 0;
}
```