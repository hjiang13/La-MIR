#include <vector>
#include <cmath>

extern "C" {

size_t _ZNKSt6vectorIfSaIfEE4sizeEv(const std::vector<float>* vec) {
    return vec->size();
}

float* _ZNSt6vectorIfSaIfEEixEm(std::vector<float>* vec, size_t index) {
    return &(*vec)[index];
}

float _ZSt5roundf(float value) {
    return std::round(value);
}

int64_t _Z21double_the_differenceSt6vectorIfSaIfEE(std::vector<float>* vec) {
    int64_t result = 0;
    int32_t i = 0;
    size_t size = _ZNKSt6vectorIfSaIfEE4sizeEv(vec);

    while (i < size) {
        float value1 = *_ZNSt6vectorIfSaIfEEixEm(vec, i);
        float value2 = *_ZNSt6vectorIfSaIfEEixEm(vec, i);
        float roundedValue2 = _ZSt5roundf(value2);
        float difference = value1 - roundedValue2;

        if (difference < 0.0001) {
            float value3 = *_ZNSt6vectorIfSaIfEEixEm(vec, i);
            if (value3 > 0.0f) {
                float value4 = *_ZNSt6vectorIfSaIfEEixEm(vec, i);
                float roundedValue4 = _ZSt5roundf(value4);
                int32_t intValue4 = static_cast<int32_t>(roundedValue4);
                if (intValue4 % 2 == 1) {
                    float value5 = *_ZNSt6vectorIfSaIfEEixEm(vec, i);
                    float roundedValue5 = _ZSt5roundf(value5);
                    int32_t intValue5 = static_cast<int32_t>(roundedValue5);
                    result += static_cast<int64_t>(intValue4 * intValue5);
                }
            }
        }
        i++;
    }
    return result;
}

}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (double_the_difference({}) == 0);
    assert (double_the_difference({5, 4}) == 25);
    assert (double_the_difference({0.1, 0.2, 0.3}) == 0 );
    assert (double_the_difference({-10, -20, -30}) == 0 );
    assert (double_the_difference({-1, -2, 8}) == 0);
    assert (double_the_difference({0.2, 3, 5}) == 34);
    
    
    long long odd_sum=0;
    vector<float> lst={};

    for (int i=-99;i<100;i+=2)
    {
        lst.push_back(i+0.0);
        if (i>0 and i%2==1) odd_sum+=i*i;
    }
  
    assert (double_the_difference(lst) == odd_sum );
}
