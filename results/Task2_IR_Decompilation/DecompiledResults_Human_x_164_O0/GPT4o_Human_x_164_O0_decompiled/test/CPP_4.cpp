#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &vec) {
    float sum = 0.0f;
    int size = vec.size();
    
    for (int i = 0; i < size; ++i) {
        sum += vec[i];
    }
    
    float mean = sum / size;
    float deviation_sum = 0.0f;
    
    for (int i = 0; i < size; ++i) {
        deviation_sum += std::abs(vec[i] - mean);
    }
    
    return deviation_sum / size;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}