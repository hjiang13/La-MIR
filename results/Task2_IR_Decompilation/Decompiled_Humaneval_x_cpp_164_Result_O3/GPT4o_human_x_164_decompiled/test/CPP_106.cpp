#include <vector>
#include <stdexcept>

void realloc_insert(std::vector<int>& vec, int value) {
    if (value < 1) {
        return;
    }

    size_t size = vec.size();
    if (size == 0) {
        vec.push_back(value);
        return;
    }

    int newSize = size + 1;
    if (newSize > vec.capacity()) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int* newData = new int[newSize];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = vec[i];
    }
    newData[size - 1] = value;

    delete[] vec.data();
    vec.data() = newData;
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
    assert (issame(f(5) , {1, 2, 6, 24, 15}));
    assert (issame(f(7) , {1, 2, 6, 24, 15, 720, 28}));
    assert (issame(f(1) , {1}));
    assert (issame(f(3) , {1, 2, 6}));
}
