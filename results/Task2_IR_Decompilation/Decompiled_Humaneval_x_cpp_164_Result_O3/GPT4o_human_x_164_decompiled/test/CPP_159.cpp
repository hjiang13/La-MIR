#include <vector>
#include <cstddef>
#include <cstring>

extern "C" void* operator new(std::size_t size) {
    return malloc(size);
}

extern "C" void operator delete(void* ptr) noexcept {
    free(ptr);
}

void example_function(std::vector<int>& vec, int a, int b, int c) {
    if (c < b) {
        vec.resize(a + c);
        vec[0] = a + c;
    } else {
        int temp = c - b;
        vec.resize(a + b);
        vec[0] = a + b;
    }
    vec[1] = nullptr; // Placeholder for pointer (to maintain structure)
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
