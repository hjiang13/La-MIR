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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (monotonic({1, 2, 4, 10}) == true);
    assert (monotonic({1, 2, 4, 20}) == true);
    assert (monotonic({1, 20, 4, 10}) == false);
    assert (monotonic({4, 1, 0, -10}) == true);
    assert (monotonic({4, 1, 1, 0}) == true);
    assert (monotonic({1, 2, 3, 2, 5, 60}) == false);
    assert (monotonic({1, 2, 3, 4, 5, 60}) == true);
    assert (monotonic({9, 9, 9, 9}) == true);
}
