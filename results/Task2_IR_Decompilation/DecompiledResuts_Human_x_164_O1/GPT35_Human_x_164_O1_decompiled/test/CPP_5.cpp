```cpp
#include <vector>

void intersperse(std::vector<int>& result, std::vector<int>& input, int value) {
    result.clear();
    int* input_begin = &input[0];
    int* input_end = input_begin + input.size();
    
    if (input_begin == input_end) {
        return;
    }
    
    result.resize(2 * input.size() - 1);
    int* result_begin = &result[0];
    int* result_end = result_begin + result.size();
    
    while (input_begin != input_end) {
        *result_begin++ = *input_begin++;
        if (input_begin != input_end) {
            *result_begin++ = value;
        }
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
    assert (issame(intersperse({}, 7), {}));
    
    assert (issame(intersperse({5, 6, 3, 2}, 8),{5, 8, 6, 8, 3, 8, 2}));
    assert (issame(intersperse({2, 2, 2}, 2),{2, 2, 2, 2, 2}));
}