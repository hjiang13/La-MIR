#include <vector>
#include <cmath>

extern "C" {
    long long double_the_difference(std::vector<float> *vec) {
        float **data = (float**)((char*)vec + sizeof(void*)); 
        float *start = *data;
        float *end = *(data + 1);
        long long diff = (long long)(start) - (long long)(end);
        
        if (diff == 0) {
            return 0;
        }
        
        long long res = 0;
        long long count = 0;
        long long max_val = (diff >> 2) > 1 ? (diff >> 2) : 1;
        
        for (long long i = 0; i < max_val; ++i) {
            float value = *(start + count);
            float rounded = roundf(value);
            float fractional_part = value - rounded;
            double dbl_fraction = (double)fractional_part;

            if (fabs(dbl_fraction) < 1e-4 && value > 0.0) {
                int rounded_int = (int)rounded;
                int mod = rounded_int % 2;

                if (mod == 1) {
                    long long square = (long long)rounded_int * (long long)rounded_int;
                    res += square;
                }
            }
            count++;
            if (count == max_val) {
                break;
            }
        }
        return res;
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
