```cpp
#include <vector>
#include <cstdlib>
#include <iostream>

class MyVector {
public:
    std::vector<int> vec;

    MyVector() {}

    int search(const std::vector<int>& input) {
        std::vector<int> tempVec;

        for (size_t i = 0; i < input.size(); ++i) {
            if (i < vec.size() && vec[i] == input[i]) {
                tempVec.push_back(vec[i]);
            }
        }

        if (tempVec.empty()) {
            return -1;
        }

        for (size_t i = 0; i < tempVec.size(); ++i) {
            if (tempVec[i] > 0) {
                return tempVec[i];
            }
        }

        return -1;
    }

    ~MyVector() {
        for (size_t i = 0; i < vec.size(); ++i) {
            free(&vec[i]);
        }
    }
};

int main() {
    MyVector myVec;
    myVec.vec = {1, 2, 3, 4, 5};

    std::vector<int> input = {3, 2, 1, 5};
    int result = myVec.search(input);
    
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```