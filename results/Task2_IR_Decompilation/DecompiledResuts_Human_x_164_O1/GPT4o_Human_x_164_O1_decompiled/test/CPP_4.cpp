#include <vector>
#include <cmath>
#include <algorithm>

float mean_absolute_deviation(std::vector<float> &vec) {
    if (vec.empty()) return 0.0f;
    
    size_t n = vec.size();
    float sum = 0.0f;

    for (size_t i = 0; i < n; ++i) {
        sum += vec[i];
    }
    
    float mean = sum / n;
    float mad_sum = 0.0f;

    for (size_t i = 0; i < n; ++i) {
        mad_sum += std::fabs(vec[i] - mean);
    }

    return mad_sum / n;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}