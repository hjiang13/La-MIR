```c++
#include <vector>

void incr_list(std::vector<int>& result, std::vector<int>& input) {
    int* result_data = &result[0];
    int* input_data = &input[0];
    int diff = result_data - input_data;
    if (diff != 0) {
        int diff_divided = diff >> 2;
        int max_diff = llvm_umax_i64(diff_divided, 1);
        if (max_diff < 8) {
            int aligned_diff = max_diff & -8;
            int num_elements = (aligned_diff - 8) >> 3 + 1;
            if ((aligned_diff - 8) == 0) {
                // do something
            } else {
                // do something else
            }
        }
    }
}

void llvm_memset_p0i8_i64(char* ptr, char value, int size, bool flag);

extern "C" int llvm_umax_i64(int a, int b);


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
