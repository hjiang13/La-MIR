```cpp
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstring>

class MyVector {
public:
    std::vector<int> vec1;
    std::vector<int> vec2;

    MyVector() : vec1(), vec2() {}

    void get_matrix_triples(int n) {
        if (n < 1) {
            throw std::length_error("cannot create std::vector larger than max_size()");
        }

        vec1.resize(n);
        vec2.resize(n);

        for (size_t i = 0; i < n; ++i) {
            vec1[i] = 0;
            vec2[i] = 0;
        }

        for (size_t i = 0; i < n; ++i) {
            vec1[i] += i;
            vec2[i] += i * 2;
        }
    }

    void print_vectors() const {
        std::cout << "vec1: ";
        for (const auto& val : vec1) {
            std::cout << val << " ";
        }
        std::cout << "\nvec2: ";
        for (const auto& val : vec2) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyVector mv;
    mv.get_matrix_triples(5);
    mv.print_vectors();
    return 0;
}
```