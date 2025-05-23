#include <vector>
#include <cmath>

using namespace std;

long long double_the_difference(const vector<float>& v) {
    long long sum = 0;
    long long size = 0;
    float* data = v.data();
    long long end = v.size();

    if (data == data + 1) {
        return 0;
    }

    long long umax = (end >> 1) + ((end >> 1) - 1);
    umax = (umax > 0) ? umax : 0;

    for (long long i = 0; i < umax; ++i) {
        float val = data[i];
        float rounded = round(val);
        float diff = val - rounded;

        if (diff < 1e-4 && val > 0) {
            int32_t integer_part = static_cast<int32_t>(rounded);
            if (integer_part % 2 != 0) {
                sum += static_cast<long long>(integer_part) * integer_part;
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
