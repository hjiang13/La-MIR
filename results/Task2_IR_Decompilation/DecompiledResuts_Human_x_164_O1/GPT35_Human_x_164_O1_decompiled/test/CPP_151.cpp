#include <vector>
#include <cmath>

std::vector<float>::_Vector_impl_data double_the_difference(std::vector<float> vec) {
    float* end_ptr = vec[0][0][0][1];
    float* start_ptr = vec[0][0][0][0];
    
    long long diff = (long long)end_ptr - (long long)start_ptr;
    if (diff == 0) {
        return 0;
    }
    
    long long num_iterations = std::max(diff >> 2, 1);
    
    for (long long i = 0; i < num_iterations; i++) {
        float val = *(start_ptr + i);
        float rounded_val = std::round(val);
        float diff_val = val - rounded_val;
        double double_val = (double)diff_val;
        
        if (double_val < 1.000000e-04 && val > 0.000000e+00) {
            int int_val = (int)rounded_val;
            if (int_val % 2 == 1) {
                num_iterations += int_val * int_val;
            }
        }
    }
    
    return num_iterations;
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
