#include <vector>
#include <algorithm>

float median(std::vector<float>& vec) {
    float* begin = vec.data();
    float* end = begin + vec.size();

    if (begin == end) {
        return 0.0f; // Handle empty vector
    }

    if (begin + 1 == end) {
        return *begin; // Handle single element
    }

    std::sort(begin, end);
    
    size_t size = end - begin;
    if (size % 2 == 0) {
        return (begin[size / 2 - 1] + begin[size / 2]) / 2.0f;
    } else {
        return begin[size / 2];
    }
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
