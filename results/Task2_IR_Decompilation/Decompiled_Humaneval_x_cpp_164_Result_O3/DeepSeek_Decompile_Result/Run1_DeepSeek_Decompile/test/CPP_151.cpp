#include <vector>
#include <cmath>

using namespace std;

long long double_the_difference(const vector<float>& v) {
    long long result = 0;
    int size = v.size();
    if (size == 0) {
        return 0;
    }

    for (int i = 0; i < size; ++i) {
        float value = v[i];
        float rounded = roundf(value);
        float difference = value - rounded;
        
        if (fabs(difference) < 1e-4 && value > 0) {
            int rounded_int = static_cast<int>(rounded);
            if (rounded_int % 2 != 0) {
                result += static_cast<long long>(rounded_int) * rounded_int;
            }
        }
    }

    return result;
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
