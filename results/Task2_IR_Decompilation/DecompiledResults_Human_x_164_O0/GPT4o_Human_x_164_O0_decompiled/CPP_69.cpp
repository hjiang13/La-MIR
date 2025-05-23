```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>

class MyVector {
public:
    std::vector<int> vec;

    MyVector() = default;

    MyVector(const std::initializer_list<int>& init) : vec(init) {}

    int search() {
        int count = 0;
        for (size_t i = 0; i < vec.size(); ++i) {
            for (size_t j = 0; j < vec.size(); ++j) {
                if (vec[i] == vec[j]) {
                    ++count;
                }
            }
        }
        return count;
    }
};
```