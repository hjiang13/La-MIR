#include <vector>
#include <stdexcept>
#include <new>

void realloc_insert(std::vector<int>& vec, int value) {
    if (vec.size() < 1) {
        vec.push_back(value);
        return;
    }

    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        if (vec[i] == value) {
            vec[i] = value;
            return;
        }
    }

    vec.push_back(value);
}

void func(std::vector<int>& vec, int value) {
    if (value < 1) {
        return;
    }
    realloc_insert(vec, value);
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
