#include <vector>
#include <cmath>

using namespace std;

int64_t double_the_difference(const vector<float>& v) {
    if (v.begin() == v.end()) {
        return 0;
    }
    
    auto begin = v.begin();
    auto end = v.end();
    int64_t num_elements = max(static_cast<int64_t>(1), (end - begin) >> 2);
    int64_t total = 0;
    int64_t i = 0;

    while (i < num_elements) {
        float val = v[i];
        float rounded = roundf(val);
        float fractional = val - rounded;
        
        if (fabs(fractional) < 1e-4 && val > 0) {
            int32_t int_val = static_cast<int32_t>(rounded);
            if (int_val % 2 != 0) {
                total += static_cast<int64_t>(int_val) * static_cast<int64_t>(int_val);
            }
        }
        i++;
    }

    return total;
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
