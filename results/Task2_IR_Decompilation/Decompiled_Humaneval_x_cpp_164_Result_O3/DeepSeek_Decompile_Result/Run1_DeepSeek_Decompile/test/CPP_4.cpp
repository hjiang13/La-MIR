#include <vector>
#include <cmath>

using namespace std;

float mean_absolute_deviation(const vector<float>& v) {
    if (v.empty()) {
        return 0.0f;
    }

    // Calculate the mean
    float sum = 0.0f;
    for (float val : v) {
        sum += val;
    }
    float mean = sum / v.size();

    // Calculate the mean absolute deviation
    float total_deviation = 0.0f;
    for (float val : v) {
        total_deviation += fabsf(val - mean);
    }
    return total_deviation / v.size();
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}