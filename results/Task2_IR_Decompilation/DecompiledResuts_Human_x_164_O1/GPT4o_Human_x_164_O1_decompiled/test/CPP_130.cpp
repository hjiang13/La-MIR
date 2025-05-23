#include <vector>
#include <iostream>
#include <stdexcept>

void realloc_insert(std::vector<int>& vec, int value) {
    if (vec.size() == 0) {
        vec.resize(1);
        vec[0] = value;
        return;
    }
    
    int size = vec.size();
    if (size < 2) {
        vec.push_back(value);
        return;
    }
    
    int newSize = size + 1;
    if (newSize > vec.capacity()) {
        vec.resize(newSize);
    }

    vec[size] = value;
}

int main() {
    std::vector<int> vec;
    realloc_insert(vec, 3);
    realloc_insert(vec, 5);
    realloc_insert(vec, 7);
    
    for (const auto& val : vec) {
        std::cout << val << std::endl;
    }
    
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
    assert (issame(tri(3) , {1, 3, 2, 8}));
    assert (issame(tri(4) , {1, 3, 2, 8, 3}));
    assert (issame(tri(5) , {1, 3, 2, 8, 3, 15}));
    assert (issame(tri(6) , {1, 3, 2, 8, 3, 15, 4}));
    assert (issame(tri(7) , {1, 3, 2, 8, 3, 15, 4, 24}));
    assert (issame(tri(8) , {1, 3, 2, 8, 3, 15, 4, 24, 5}));
    assert (issame(tri(9) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35}));
    assert (issame(tri(20) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11}));
    assert (issame(tri(0) , {1}));
    assert (issame(tri(1) , {1, 3}));
}
