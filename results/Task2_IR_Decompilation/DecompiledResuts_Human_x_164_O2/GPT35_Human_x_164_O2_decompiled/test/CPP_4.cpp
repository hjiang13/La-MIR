#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &vec) {
    float sum = 0.0;
    float mean = 0.0;
    int size = vec.size();

    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }

    mean = sum / size;

    float mad = 0.0;
    for (int i = 0; i < size; i++) {
        mad += std::fabs(vec[i] - mean);
    }

    mad /= size;

    return mad;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}