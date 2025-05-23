```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>

class VectorWrapper {
public:
    VectorWrapper() : v() {}

    VectorWrapper(std::initializer_list<int> init) : v(init) {}

    void pluck(const VectorWrapper& other) {
        for (size_t i = 0; i < other.v.size(); ++i) {
            int value = other.v[i];
            if (value % 2 == 0) {
                v.push_back(value);
            }
        }
    }

    size_t size() const {
        return v.size();
    }

    int operator[](size_t index) const {
        if (index >= v.size()) {
            throw std::out_of_range("Index out of range");
        }
        return v[index];
    }

private:
    std::vector<int> v;
};

int main() {
    VectorWrapper vec1 = {1, 2, 3, 4, 5};
    VectorWrapper vec2 = {6, 7, 8, 9, 10};

    vec1.pluck(vec2);

    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << std::endl;
    }

    return 0;
}
```