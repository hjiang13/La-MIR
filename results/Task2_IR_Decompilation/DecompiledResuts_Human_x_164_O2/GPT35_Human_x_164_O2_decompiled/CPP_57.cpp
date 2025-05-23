```c++
#include <vector>
#include <iostream>

bool monotonic(std::vector<float> &vec) {
    float* data = vec.data();
    float* end = data + vec.size();

    int count = 0;
    for (int i = 0; i < vec.size() - 1; ++i) {
        if (data[i] > data[i + 1]) {
            count++;
        }
    }

    return count != 2;
}

int main() {
    std::vector<float> v = {1.0, 2.0, 3.0, 4.0, 5.0};
    bool result = monotonic(v);

    if (result) {
        std::cout << "Vector is monotonic" << std::endl;
    } else {
        std::cout << "Vector is not monotonic" << std::endl;
    }

    return 0;
}
```