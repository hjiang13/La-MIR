#include <vector>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    result.reserve(input.size());

    int* input_data = input.data();
    int* result_data = result.data();

    int* input_end = input_data + input.size();
    int* result_end = result_data + result.size();

    int max_value = 0;

    for (int* i = input_data; i != input_end; ++i) {
        if (*i > max_value) {
            max_value = *i;
        }

        *result_data = max_value;
        ++result_data;
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
     assert (issame(rolling_max({}),{}));
    assert (issame(rolling_max({1, 2, 3, 4}) , {1, 2, 3, 4}));
     assert (issame(rolling_max({4, 3, 2, 1}),{4, 4, 4, 4}));
      assert (issame(rolling_max({3, 2, 3, 100, 3}) ,{3, 3, 3, 100, 100}));
}