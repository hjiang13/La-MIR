#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    float* result_data = nullptr;
    int size = 2; 
    result.resize(size);
    result_data = result.data();
    std::memset(result_data, 0, size * sizeof(float));

    const float* input_data = input.data();
    if (input_data == nullptr) return;

    float first_elem = input_data[0];
    float second_elem = input_data[1];

    if (first_elem > second_elem) {
        result_data[0] = second_elem;
        result_data[1] = first_elem;
    } else {
        result_data[0] = first_elem;
        result_data[1] = second_elem;
    }

    for (int i = 2; i < input.size(); ++i) {
        float current_elem = input_data[i];
        if (current_elem < result_data[0]) {
            result_data[1] = result_data[0];
            result_data[0] = current_elem;
        } else if (current_elem < result_data[1]) {
            result_data[1] = current_elem;
        }
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
    assert (issame(find_closest_elements({1.0, 2.0, 3.9, 4.0, 5.0, 2.2}) , {3.9, 4.0}));
    assert (issame(find_closest_elements({1.0, 2.0, 5.9, 4.0, 5.0}) , {5.0, 5.9} ));
    assert (issame(find_closest_elements({1.0, 2.0, 3.0, 4.0, 5.0, 2.2}) ,{2.0, 2.2}));
     assert (issame(find_closest_elements({1.0, 2.0, 3.0, 4.0, 5.0, 2.0}) ,{2.0, 2.0}));
      assert (issame(find_closest_elements({1.1, 2.2, 3.1, 4.1, 5.1}) , {2.2, 3.1}));
}
