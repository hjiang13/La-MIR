#include <vector>

class std::vector {
public:
    struct _Vector_base {
        struct _Vector_impl {
            float* _M_start;
            float* _M_finish;
            float* _M_end_of_storage;
        } _M_impl;
    } _M_start;
};

bool monotonic(std::vector<float> &v) {
    float* start = v._M_start._M_impl._M_start;
    float* finish = v._M_start._M_impl._M_finish;
    float* end_of_storage = v._M_start._M_impl._M_end_of_storage;

    int64_t size = (int64_t)((uint64_t)finish - (uint64_t)start);
    int64_t half_size = size / 2;

    int32_t i = 0;
    int32_t j = 0;
    int32_t k = 0;

    while (i < half_size) {
        float a = start[i];
        float b = start[size - i - 1];
        if (a > b) {
            j = i + 1;
            k = size - i - 1;
            while (j < k) {
                float c = start[j];
                float d = start[k];
                if (c > d) {
                    return false;
                }
                j++;
                k--;
            }
        }
        i++;
    }

    return true;
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
