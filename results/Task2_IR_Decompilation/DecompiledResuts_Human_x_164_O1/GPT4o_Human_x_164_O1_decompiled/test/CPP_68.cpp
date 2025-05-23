#include <vector>
#include <stdexcept>
#include <cstring>

void pluck(std::vector<int>& out, const std::vector<int>& in) {
    out.clear();
    if (in.empty()) {
        return;
    }

    size_t size = in.size();
    for (size_t i = 0; i < size; ++i) {
        if (in[i] % 2 == 0) {
            out.push_back(in[i]);
        }
    }
}

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
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
