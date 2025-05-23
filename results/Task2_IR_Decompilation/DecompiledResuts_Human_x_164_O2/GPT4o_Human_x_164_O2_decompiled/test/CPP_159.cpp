#include <vector>
#include <cstring>

extern "C" void* operator new(std::size_t size) {
    return malloc(size);
}

extern "C" void operator delete(void* ptr) noexcept {
    free(ptr);
}

extern "C" void eati(int a, int b, int c, int d, std::vector<int>& vec) {
    if (d < c) {
        int sum = d + a;
        vec.resize(2);
        vec[0] = sum;
        vec[1] = 0;
    } else {
        int diff = d - c;
        int sum = c + a;
        vec.resize(2);
        vec[0] = sum;
        vec[1] = diff;
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
    assert (issame(eat(5, 6, 10) , {11, 4}));
    assert (issame(eat(4, 8, 9) , {12, 1}));
    assert (issame(eat(1, 10, 10) , {11, 0}));
    assert (issame(eat(2, 11, 5) , {7, 0}));
    
    assert (issame(eat(4, 5, 7) , {9, 2}));
    assert (issame(eat(4, 5, 1) , {5, 0}));
}
