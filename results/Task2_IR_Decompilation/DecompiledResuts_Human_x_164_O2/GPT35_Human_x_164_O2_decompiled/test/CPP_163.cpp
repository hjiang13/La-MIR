```cpp
#include <vector>

void generate_integers(std::vector<int>& vec, int start, int end) {
    int actual_start = (end < start) ? start : end;
    int actual_end = (end < start) ? end : start;
    
    vec.clear();
    
    for (int i = actual_start; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        
        if (vec.size() == vec.capacity()) {
            throw std::length_error("vector::_M_realloc_insert");
        }
        
        vec.push_back(i);
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
    assert (issame(generate_integers(2, 10) , {2, 4, 6, 8}));
    assert (issame(generate_integers(10, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(132, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(17,89) , {}));
}
