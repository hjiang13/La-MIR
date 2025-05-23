#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &vec) {
    size_t size = vec.size();
    if (size == 0) return 0.0f;

    float sum = 0.0f;
    for (size_t i = 0; i < size; ++i) {
        sum += vec[i];
    }
    float mean = sum / size;

    sum = 0.0f;
    for (size_t i = 0; i < size; ++i) {
        sum += std::fabs(vec[i] - mean);
    }

    return sum / size;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}