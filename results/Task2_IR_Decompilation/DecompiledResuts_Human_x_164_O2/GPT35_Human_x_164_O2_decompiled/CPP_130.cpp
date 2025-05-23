```c
#include <vector>
#include <iostream>

void tr(std::vector<int>& vec, int val) {
    if (val == 0) {
        vec.clear();
    } else if (val < 2) {
        vec.push_back(1);
        vec.push_back(3);
    } else {
        int size = vec.size();
        int* data = new int[size + 1];
        std::copy(vec.begin(), vec.end(), data);
        data[size] = val;
        delete[] vec.data();
        vec = std::vector<int>(data, data + size + 1);
    }
}

int main() {
    std::vector<int> vec;
    tr(vec, 5);

    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```