#include <vector>
#include <cmath>

using namespace std;

float mean_absolute_deviation(const vector<float>& v) {
    if (v.empty()) {
        return 0.0f;
    }
    size_t n = v.size();
    float sum = 0.0f;
    for (size_t i = 0; i < n; ++i) {
        sum += v[i];
    }
    float mean = sum / n;
    float total = 0.0f;
    for (size_t i = 0; i < n; ++i) {
        total += fabs(v[i] - mean);
    }
    return total / n;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}