#include <vector>
#include <cstring>

extern "C" void incr_list(std::vector<int>& a, std::vector<int>& b) {
    int* b_data = b.data();
    int* a_data = a.data();
    if (b_data == a_data) return;

    size_t b_size = b.size();
    if (b_size < 8) {
        size_t shift = b_size >> 2;
        shift = (shift < 1) ? 1 : shift;
        if (shift < 8) {
            shift = (shift & ~7) - 8;
        }

        for (size_t i = 0; i < (shift + 1); ++i) {
            a_data[i] += 1;
            b_data[i] += 1;
        }

        if (shift == 0) return;

        for (size_t i = shift; i < b_size; ++i) {
            a_data[i] += 1;
            b_data[i] += 1;
        }
    } else {
        for (size_t i = 0; i < b_size; ++i) {
            a_data[i] += 1;
            b_data[i] += 1;
        }
    }

    std::memset(reinterpret_cast<void*>(&a), 0, sizeof(std::vector<int>));
    std::memset(reinterpret_cast<void*>(&b), 0, sizeof(std::vector<int>));
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
