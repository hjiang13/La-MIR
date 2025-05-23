#include <vector>
#include <cmath>

int double_the_difference(std::vector<float> &v) {
    float *begin = &v[0];
    float *end = &v[0];
    
    long diff = begin - end;
    if (diff == 0) {
        return 0;
    }
    
    long max_diff = std::max(diff >> 2, 1);
    
    long sum = 0;
    for (int i = 0; i < max_diff; i++) {
        float val = *(end + i);
        float rounded_val = std::round(val);
        double diff = val - rounded_val;
        
        bool condition = (diff < 0.0001) && (val > 0.0);
        
        if (condition) {
            int rounded_val_int = static_cast<int>(rounded_val);
            if (rounded_val_int % 2 == 1) {
                sum += rounded_val_int * rounded_val_int;
            }
        }
    }
    
    return sum;
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
