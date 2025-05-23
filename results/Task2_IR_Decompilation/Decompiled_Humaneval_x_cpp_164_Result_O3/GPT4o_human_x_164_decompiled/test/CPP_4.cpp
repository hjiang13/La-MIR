#include <vector>
#include <cmath>
#include <cstdint>

float mean_absolute_deviation(std::vector<float> &vec) {
    size_t n = vec.size();
    if (n == 0) return 0.0f;

    float sum = 0.0f;
    float mean = 0.0f;

    for (size_t i = 0; i < n; ++i) {
        sum += vec[i];
    }
    mean = sum / n;

    float mad = 0.0f;
    for (size_t i = 0; i < n; ++i) {
        mad += std::fabs(vec[i] - mean);
    }

    return mad / n;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}