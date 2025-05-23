```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>

class MyVector {
public:
    MyVector(int size1, int size2, int size3) {
        if (size1 > size3) {
            int *data = new int[2];
            data[0] = size1 + size2;
            data[1] = 0;
            std::initializer_list<int> initList(data, 2);
            vec = std::vector<int>(initList);
            delete[] data;
        } else {
            int *data = new int[2];
            data[0] = size2;
            data[1] = size3 - size2;
            std::initializer_list<int> initList(data, 2);
            vec = std::vector<int>(initList);
            delete[] data;
        }
    }

    ~MyVector() = default;

private:
    std::vector<int> vec;
};
```