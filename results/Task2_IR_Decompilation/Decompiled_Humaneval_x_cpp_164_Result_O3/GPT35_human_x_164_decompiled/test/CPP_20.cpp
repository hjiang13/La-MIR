#include <vector>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();

    if (input.size() <= 1) {
        return;
    }

    for (size_t i = 0; i < input.size() - 1; ++i) {
        if (input[i] > input[i + 1]) {
            result.push_back(input[i]);
            result.push_back(input[i + 1]);
        }
    }
}

int main() {
    std::vector<float> input = {3.14, 2.71, 1.618, 0.0};
    std::vector<float> result;

    find_closest_elements(result, input);

    return 0;
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
