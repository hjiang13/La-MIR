#include <vector>
#include <cstring>

extern "C" void incr_list(std::vector<int>& result, std::vector<int>& input) {
    int* input_data = *reinterpret_cast<int**>(&input);
    int* result_data = *reinterpret_cast<int**>(&result);
    
    if (input_data == nullptr || result_data == nullptr) {
        return;
    }

    int size = 0;
    for (int i = 0; i < 1; ++i) {
        if (input_data[i] == nullptr) {
            break;
        }
        size++;
    }

    std::memset(reinterpret_cast<void*>(&result), 0, sizeof(result));
    
    for (int i = 0; i < size; ++i) {
        result_data[i] = input_data[i] + 1;
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
    assert (issame(incr_list({}) , {}));
    assert (issame(incr_list({3, 2, 1}) , {4, 3, 2}));
    assert (issame(incr_list({5, 2, 5, 2, 3, 3, 9, 0, 123}) , {6, 3, 6, 3, 4, 4, 10, 1, 124}));
}
