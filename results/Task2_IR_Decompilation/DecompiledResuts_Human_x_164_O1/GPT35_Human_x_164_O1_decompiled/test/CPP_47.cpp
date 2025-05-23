```cpp
#include <vector>
#include <algorithm>

float median(std::vector<float> vec) {
    if (vec.size() == 0) {
        return 0;
    }

    std::sort(vec.begin(), vec.end());

    int middle = vec.size() / 2;
    float median_value = 0;

    if (vec.size() % 2 == 0) {
        median_value = (vec[middle - 1] + vec[middle]) / 2.0;
    } else {
        median_value = vec[middle];
    }

    return median_value;
}

int main() {
    std::vector<float> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
    float result = median(numbers);

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(median({3, 1, 2, 4, 5}) - 3)<1e-4);
    assert (abs(median({-10, 4, 6, 1000, 10, 20}) -8.0)<1e-4);
    assert (abs(median({5}) - 5)<1e-4);
    assert (abs(median({6, 5}) - 5.5)<1e-4);
    assert (abs(median({8, 1, 3, 9, 9, 2, 7}) - 7)<1e-4 );
}
