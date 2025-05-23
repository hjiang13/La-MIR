```c
#include <vector>
#include <cmath>

float mean_absolute_deviation(std::vector<float> &data) {
    float sum = 0.0f;
    float mean = 0.0f;
    
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i];
    }
    
    mean = sum / static_cast<float>(data.size());
    
    float absolute_deviation_sum = 0.0f;
    for (size_t i = 0; i < data.size(); ++i) {
        float deviation = data[i] - mean;
        absolute_deviation_sum += std::fabs(deviation);
    }
    
    float mean_absolute_deviation = absolute_deviation_sum / static_cast<float>(data.size());
    
    return mean_absolute_deviation;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}