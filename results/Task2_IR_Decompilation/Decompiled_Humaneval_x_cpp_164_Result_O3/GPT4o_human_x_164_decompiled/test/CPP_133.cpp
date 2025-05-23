#include <vector>
#include <cmath>
#include <cstdint>

int sum_squares(std::vector<float> const& vec) {
    if (vec.empty()) return 0;
    
    int32_t result = 0;
    for (size_t i = 0; i < vec.size(); i += 2) {
        float x = std::ceil(vec[i]);
        result += static_cast<int32_t>(x * x);

        if (i + 1 < vec.size()) {
            float y = std::ceil(vec[i + 1]);
            result += static_cast<int32_t>(y * y);
        }
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_squares({1,2,3})==14);
    assert (sum_squares({1.0,2,3})==14);
    assert (sum_squares({1,3,5,7})==84);
    assert (sum_squares({1.4,4.2,0})==29);
    assert (sum_squares({-2.4,1,1})==6);
    assert (sum_squares({100,1,15,2})==10230);
    assert (sum_squares({10000,10000})==200000000);
    assert (sum_squares({-1.4,4.6,6.3})==75);
    assert (sum_squares({-1.4,17.9,18.9,19.9})==1086);
    assert (sum_squares({0})==0);
    assert (sum_squares({-1})==1);
    assert (sum_squares({-1,1,0})==2);
}
