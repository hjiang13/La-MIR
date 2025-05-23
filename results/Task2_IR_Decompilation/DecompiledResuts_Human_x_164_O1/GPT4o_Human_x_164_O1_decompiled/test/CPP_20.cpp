#include <vector>
#include <stdexcept>
#include <cmath>
#include <cstring>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    float temp[2];
    float* input_start = const_cast<float*>(input.data());
    float* input_end = input_start + input.size();
    size_t count = 0;

    while (input_start < input_end) {
        float first = *input_start++;
        float second = input_start < input_end ? *input_start++ : first;

        if (first > second) {
            temp[0] = first;
            temp[1] = second;
        } else {
            temp[0] = second;
            temp[1] = first;
        }

        if (count == result.size()) {
            throw std::length_error("cannot create std::vector larger than max_size()");
        }

        std::memcpy(result.data() + count * 2, temp, 2 * sizeof(float));
        count++;
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
