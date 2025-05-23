#include <vector>
#include <stdexcept>
#include <cstring>

class MyVector {
public:
    std::vector<int> data;

    void realloc_insert(int size) {
        if (size == 0) {
            data.clear();
            return;
        }
        
        if (size < 2) {
            data.resize(2);
            return;
        }

        int newSize = size + 1;
        if (newSize > data.capacity()) {
            throw std::length_error("vector::_M_realloc_insert");
        }

        data.resize(newSize);
        
        for (int i = 0; i < size; ++i) {
            data[i] = i + 1; // Example initialization
        }
    }
};

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
