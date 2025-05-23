#include <vector>
#include <algorithm>

float median(std::vector<float>& vec) {
    float result;
    std::sort(vec.begin(), vec.end());
    size_t size = vec.size();
    if (size % 2 == 1) {
        result = vec[size / 2];
    } else {
        result = (vec[size / 2 - 1] + vec[size / 2]) / 2.0f;
    }
    return result;
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
