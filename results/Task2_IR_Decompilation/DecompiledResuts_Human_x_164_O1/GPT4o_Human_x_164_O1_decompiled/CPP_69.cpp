```cpp
#include <vector>
#include <iostream>

class VectorWrapper {
public:
    std::vector<int> vec1;
    std::vector<VectorWrapper*> vec2;

    VectorWrapper() {
        vec1.reserve(10);
        vec2.reserve(10);
    }

    int search(const std::vector<int>& inputVec) {
        int result = -1;
        for (size_t i = 0; i < inputVec.size(); ++i) {
            if (i < vec1.size() && inputVec[i] == vec1[i]) {
                result = i;
                break;
            }
        }
        return result;
    }

    ~VectorWrapper() {
        for (auto ptr : vec2) {
            delete ptr;
        }
    }
};

int main() {
    VectorWrapper vw;
    std::vector<int> inputVec = {1, 2, 3, 4, 5};
    int index = vw.search(inputVec);
    std::cout << "Index: " << index << std::endl;
    return 0;
}
```