#include <vector>
#include <stdexcept>
#include <cstring>

void realloc_insert(std::vector<int>& vec, int value) {
    if (value == 0) {
        std::memset(&vec, 0, sizeof(vec));
        return;
    }

    if (value < 2) {
        int newSize = value + 1;
        vec.resize(newSize);
        return;
    }

    int* data = new int[4];
    data[0] = 1;
    data[1] = 3;
    
    for (int i = 0; i < value + 1; ++i) {
        if (i % 2 == 0) {
            data[i] = 0;
        } else {
            data[i] = 1;
        }
    }

    if (vec.size() < value + 1) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int* newData = new int[value * 4];
    std::memmove(newData, data, value * sizeof(int));
    delete[] data;

    vec.push_back(newData[0]);
    vec.push_back(newData[1]);
    vec.push_back(newData[2]);
    
    delete[] newData;
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
