#include <vector>
#include <algorithm>
#include <limits>

void rescale_to_unit(std::vector<float>& vec) {
    float min_val = 1.0e+05f;
    float max_val = -1.0e+05f;

    for (size_t i = 0; i < vec.size(); ++i) {
        float value = vec[i];
        if (value < min_val) {
            min_val = value;
        }
        if (value > max_val) {
            max_val = value;
        }
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        float value = vec[i];
        vec[i] = (value - min_val) / (max_val - min_val);
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
