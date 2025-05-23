```c
#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &vec) {
    float sum = 0.0;
    int size = vec.size();
    
    for (int i = 0; i < size; i++) {
        sum += vec[i];
    }
    
    float mean = sum / size;
    float abs_diff_sum = 0.0;
    
    for (int i = 0; i < size; i++) {
        float diff = vec[i] - mean;
        abs_diff_sum += std::abs(diff);
    }
    
    float mad = abs_diff_sum / size;
    return mad;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}