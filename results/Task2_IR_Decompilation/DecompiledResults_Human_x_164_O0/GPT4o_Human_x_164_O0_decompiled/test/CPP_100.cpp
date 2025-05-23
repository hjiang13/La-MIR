#include <vector>
#include <initializer_list>
#include <stdexcept>

class Allocator {
public:
    Allocator() {}
    ~Allocator() {}
};

void make_a_pile(std::vector<int>& vec, int size) {
    Allocator allocator;
    int value = size;
    vec.push_back(value);
    for (int i = 1; i < size; ++i) {
        value = vec[i - 1] + 2;
        vec.push_back(value);
    }
}

int main() {
    std::vector<int> vec;
    make_a_pile(vec, 10);
    return 0;
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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}
