```c++
#include <vector>

void pluck(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> *in = const_cast<std::vector<int>*>(&input);
    int *in_begin = &(*in)[0];
    int *in_end = in_begin + in->size();
    
    int *out_begin = &result[0];
    int *out_end = out_begin + result.size();
    
    std::memset(&result[0], 0, result.size() * sizeof(int));
    
    if (in->data() == in_end) {
        return;
    }
    
    for (int i = 0; i < in->size(); ++i) {
        int val = in_begin[i];
        if ((val & 1) == 0) {
            continue;
        }
        
        int *out_ptr = out_begin;
        while (out_ptr != out_end && *out_ptr < val) {
            ++out_ptr;
        }
        
        if (out_ptr == out_end) {
            break;
        }
        
        std::copy_backward(out_ptr, out_end - 1, out_end);
        *out_ptr = val;
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
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
