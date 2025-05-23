#include <vector>
#include <algorithm>
#include <cmath>

extern "C" {
    long long double_the_difference(std::vector<float> &vec) {
        float* data = vec.data();
        float* end = data + vec.size();
        
        if (data == end) {
            return 0;
        }

        long long result = 0;
        long long size = end - data;

        for (long long i = 0; i < size; ++i) {
            float value = data[i];
            float rounded = roundf(value);
            float difference = value - rounded;
            double double_diff = static_cast<double>(difference);
            
            if (fabs(double_diff) < 1e-4 && value > 0.0f) {
                int rounded_int = static_cast<int>(rounded);
                int mod = rounded_int % 2;
                if (mod == 1) {
                    long long square = static_cast<long long>(rounded_int) * rounded_int;
                    result += square;
                }
            }
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
