```c++
#include <vector>
#include <cmath>

int sum_squares(std::vector<float> *v) {
    float *begin = &((*v)[0]);
    float *end = &((*v)[0]);

    long long diff = (long long)begin - (long long)end;
    if (diff == 0) {
        return 0;
    }

    long long num_elements = diff >> 2;
    num_elements = std::max(num_elements, (long long)1);
    bool odd_num_elements = (num_elements & 1) == 1;
    
    float sum = 0.0f;
    for (int i = 0; i < num_elements; i++) {
        float value = std::ceil(*(end + i));
        float squared_value = value * value;
        sum += squared_value;
    }

    if (odd_num_elements) {
        float value = std::ceil(*(end + num_elements));
        float squared_value = value * value;
        sum += squared_value;
    }

    return static_cast<int>(sum);
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
