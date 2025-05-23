```cpp
#include <vector>
#include <algorithm>

template<typename T>
long double double_the_difference(std::vector<T> &vec) {
    if (vec.size() == 0) {
        return 0;
    }

    long long max_diff = 1;
    long long sum = 0;

    for (int i = 0; i < vec.size(); i++) {
        T val = vec[i];
        T rounded_val = std::round(val);
        double diff = val - rounded_val;

        if (diff < 1.000000e-04 && val > 0.000000e+00) {
            int rounded_int = static_cast<int>(rounded_val);
            if (rounded_int % 2 == 1) {
                sum += static_cast<long long>(rounded_int * rounded_int);
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
