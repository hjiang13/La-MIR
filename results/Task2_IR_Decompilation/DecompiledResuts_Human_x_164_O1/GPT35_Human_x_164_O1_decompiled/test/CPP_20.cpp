```cpp
#include <vector>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    std::vector<float> temp(2);
    
    if (input.size() < 2) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }
    
    for (size_t i = 0; i < input.size() - 1; ++i) {
        float diff = std::fabs(input[i] - input[i + 1]);
        float current_diff = std::fabs(temp[0] - temp[1]);
        
        if (diff < current_diff) {
            temp[0] = input[i];
            temp[1] = input[i + 1];
        }
    }
    
    result.assign(temp.begin(), temp.end());
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
