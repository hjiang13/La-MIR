#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdint>
#include <limits>

void rescale_to_unit(std::vector<float>& output, const std::vector<float>& input) {
    const float minValue = -1.0e+5;
    const float maxValue = 1.0e+5;

    float currentMin = maxValue;
    float currentMax = minValue;

    for (size_t i = 0; i < input.size(); ++i) {
        currentMin = std::min(currentMin, input[i]);
        currentMax = std::max(currentMax, input[i]);
    }

    output.resize(3);
    output[0] = currentMin;
    output[1] = currentMax;

    for (size_t i = 0; i < input.size(); ++i) {
        float scaledValue = (input[i] - currentMin) / (currentMax - currentMin);
        output.push_back(scaledValue);
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(rescale_to_unit({2.0, 49.9}) , {0.0, 1.0}));
     assert (issame(rescale_to_unit({100.0, 49.9}) ,{1.0, 0.0})); 
     assert (issame(rescale_to_unit({1.0, 2.0, 3.0, 4.0, 5.0}) , {0.0, 0.25, 0.5, 0.75, 1.0}));
    assert (issame(rescale_to_unit({2.0, 1.0, 5.0, 3.0, 4.0}) , {0.25, 0.0, 1.0, 0.5, 0.75}));
     assert (issame(rescale_to_unit({12.0, 11.0, 15.0, 13.0, 14.0}) ,{0.25, 0.0, 1.0, 0.5, 0.75}));
}
