#include <vector>
#include <algorithm>

float median(std::vector<float>& vec) {
    if (vec.size() == 0) return 0.0f;
    if (vec.size() == 1) return vec[0];

    float* begin = vec.data();
    float* end = begin + vec.size();

    std::sort(begin, end);

    size_t size = vec.size();
    if (size % 2 == 0) {
        return (begin[size / 2 - 1] + begin[size / 2]) / 2.0f;
    } else {
        return begin[size / 2];
    }
}

void insertion_sort(float* begin, float* end) {
    for (float* i = begin + 1; i < end; ++i) {
        float key = *i;
        float* j = i - 1;
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

void make_heap(float* begin, float* end) {
    std::make_heap(begin, end);
}

int main() {
    std::vector<float> data = {3.0f, 1.0f, 2.0f, 5.0f, 4.0f};
    float med = median(data);
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
