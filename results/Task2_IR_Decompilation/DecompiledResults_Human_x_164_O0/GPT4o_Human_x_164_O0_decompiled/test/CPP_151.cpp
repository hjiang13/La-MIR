#include <vector>
#include <cmath>

long long double_the_difference(std::vector<float> &vec) {
    long long result = 0;
    int index = 0;

    while (true) {
        if (index >= vec.size()) {
            break;
        }
        
        float current = vec[index];
        float rounded = round(current);
        float difference = current - rounded;

        if (fabs(difference) < 1e-4) {
            index++;
            continue;
        }

        if (current > 0.0f) {
            float roundedCurrent = round(current);
            int intRoundedCurrent = static_cast<int>(roundedCurrent);
            int intCurrent = static_cast<int>(current);
            int product = intRoundedCurrent * intCurrent;
            result += product;
        }
        
        index++;
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
