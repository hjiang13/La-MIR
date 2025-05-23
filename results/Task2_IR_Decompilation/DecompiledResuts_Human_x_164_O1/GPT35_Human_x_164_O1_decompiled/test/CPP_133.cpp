```cpp
#include <vector>
#include <cmath>

int sum_squares(std::vector<float> &vec) {
    float* data_begin = vec._M_impl._M_start._M_ptr;
    float* data_end = vec._M_impl._M_finish._M_ptr;
    int count = 0;

    if (data_begin == data_end) {
        return count;
    }

    int max_count = std::max((data_end - data_begin) >> 2, 1);

    for (int i = 0; i < max_count; i++) {
        float val = std::ceil(*data_begin);
        float square = val * val;
        float index_float = static_cast<float>(count);
        float result = square + index_float;
        count = static_cast<int>(result);
        data_begin++;
    }

    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_squares({1,2,3})==14);
    assert (sum_squares({1.0,2,3})==14);
    assert (sum_squares({1,3,5,7})==84);
    assert (sum_squares({1.4,4.2,0})==29);
    assert (sum_squares({-2.4,1,1})==6);
    assert (sum_squares({100,1,15,2})==10230);
    assert (sum_squares({10000,10000})==200000000);
    assert (sum_squares({-1.4,4.6,6.3})==75);
    assert (sum_squares({-1.4,17.9,18.9,19.9})==1086);
    assert (sum_squares({0})==0);
    assert (sum_squares({-1})==1);
    assert (sum_squares({-1,1,0})==2);
}
