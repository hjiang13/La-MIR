#include <vector>
#include <cstddef>
#include <cstring>
#include <new>

void pluck(std::vector<int> &result, const std::vector<int> &input) {
    using namespace std;
    size_t input_size = input.size();
    size_t result_size = 0;

    result.clear();
    result.reserve(input_size);

    for (size_t i = 0; i < input_size; ++i) {
        if ((input[i] & 1) == 0) {
            result.push_back(input[i]);
            result_size++;
        }
    }

    result.resize(result_size);
}

extern "C" {
    void *operator new(size_t size) noexcept {
        return ::operator new(size);
    }

    void operator delete(void *ptr) noexcept {
        ::operator delete(ptr);
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
