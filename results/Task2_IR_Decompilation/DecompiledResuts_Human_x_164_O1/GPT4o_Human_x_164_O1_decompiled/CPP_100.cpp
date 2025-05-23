```cpp
#include <vector>
#include <stdexcept>
#include <iostream>

void make_a_pile(std::vector<int>& vec, int size) {
    if (size < 1) return;

    vec.resize(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = i + 2;  // Fill the vector with values starting from 2
    }
}

int main() {
    std::vector<int> my_vector;
    make_a_pile(my_vector, 10);

    for (const int& value : my_vector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
```