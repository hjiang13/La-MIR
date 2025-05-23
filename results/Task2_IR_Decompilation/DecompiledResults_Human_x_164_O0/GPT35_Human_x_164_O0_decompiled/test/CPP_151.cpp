```c
#include <vector>
#include <cmath>

double double_the_difference(std::vector<float>& vec) {
    double result = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        float val1 = std::round(vec[i]);
        if (std::abs(val1 - std::round(vec[i + 1])) < 0.0001) {
            if (vec[i + 1] > 0) {
                if (static_cast<int>(std::round(vec[i])) % 2 == 1) {
                    result += static_cast<int>(std::round(vec[i])) * static_cast<int>(std::round(vec[i + 1]));
                }
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
