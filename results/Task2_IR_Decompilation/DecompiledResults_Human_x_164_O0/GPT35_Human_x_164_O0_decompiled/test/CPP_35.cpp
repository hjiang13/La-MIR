#include <vector>

float max_element(std::vector<float>& vec) {
    float max_val = -1.0e+04;
    int index = 0;
    
    for (int i = 0; i < vec.size(); i++) {
        if (max_val < vec[i]) {
            max_val = vec[i];
        }
    }
    
    return max_val;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}
