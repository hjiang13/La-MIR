#include <vector>
#include <algorithm>
#include <cmath>

extern "C" {
    long long double_the_difference(std::vector<float>* vec) {
        float* data = vec->_Vector_base::_Vector_impl._Vector_impl_data;
        float* begin = data[0];
        float* end = data[1];
        
        long long ptr_diff = reinterpret_cast<long long>(begin) - reinterpret_cast<long long>(end);
        if (ptr_diff == 0) {
            return 0;
        }

        long long shift = ptr_diff >> 2;
        long long max_val = std::max(shift, 1LL);

        long long count = 0;
        for (long long i = 0; i < max_val; ++i) {
            float value = *(begin + i);
            float rounded_value = std::round(value);
            float difference = value - rounded_value;
            double extended_difference = static_cast<double>(difference);

            if (std::abs(extended_difference) < 1e-4 && value > 0.0) {
                int rounded_int = static_cast<int>(rounded_value);
                int mod_result = rounded_int % 2;

                if (mod_result == 1) {
                    count += (rounded_int * rounded_int);
                }
            }
        }
        return count;
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
