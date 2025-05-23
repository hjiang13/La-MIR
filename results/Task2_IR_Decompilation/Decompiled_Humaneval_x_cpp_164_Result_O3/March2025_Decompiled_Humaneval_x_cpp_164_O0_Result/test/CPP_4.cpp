#include <vector>
#include <cmath>

float mean_absolute_deviation(const std::vector<float>& vec) {
    float sum = 0.0f;
    for (size_t i = 0; i < vec.size(); ++i) {
        sum += vec[i];
    }
    float mean = sum / static_cast<float>(vec.size());

    float mad = 0.0f;
    for (size_t i = 0; i < vec.size(); ++i) {
        mad += std::abs(vec[i] - mean);
    }
    return mad / static_cast<float>(vec.size());
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}