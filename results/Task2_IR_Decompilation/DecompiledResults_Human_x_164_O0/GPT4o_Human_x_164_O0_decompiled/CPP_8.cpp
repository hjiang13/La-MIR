```cpp
#include <vector>
#include <initializer_list>
#include <stdexcept>

class MyVector {
public:
    MyVector(std::initializer_list<int> list) {
        vec = new std::vector<int>(list);
    }

    ~MyVector() {
        delete vec;
    }

    void sum_product(MyVector& other) {
        if (!vec || !other.vec) throw std::runtime_error("Vector is null");

        int sum = 0;
        int product = 1;
        size_t size = vec->size();

        for (size_t i = 0; i < size; ++i) {
            sum += (*vec)[i];
            product *= (*vec)[i];
        }

        result = {sum, product};
    }

    const std::vector<int>& getResult() const {
        return result;
    }

private:
    std::vector<int>* vec;
    std::vector<int> result;
};

int main() {
    MyVector v1 = {1, 2, 3};
    MyVector v2 = {4, 5, 6};

    v1.sum_product(v2);

    return 0;
}
```