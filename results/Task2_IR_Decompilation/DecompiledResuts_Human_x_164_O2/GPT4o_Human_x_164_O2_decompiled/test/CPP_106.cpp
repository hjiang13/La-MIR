#include <vector>
#include <stdexcept>

void realloc_insert(std::vector<int>& vec, int value) {
    if (vec.size() < 1) {
        vec.resize(1);
        vec[0] = value;
        return;
    }

    int* old_data = vec.data();
    int new_size = vec.size() + 1;

    if (new_size > vec.capacity()) {
        int* new_data = new int[new_size];
        std::memcpy(new_data, old_data, vec.size() * sizeof(int));
        delete[] old_data;
        vec.data() = new_data;
    }

    vec[new_size - 1] = value;
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
