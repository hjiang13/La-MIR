#include <vector>
#include <stdexcept>
#include <cstring>

void generate_integers(std::vector<int>& vec, int start, int end) {
    if (end < start) {
        end = start;
    }
    int actual_end = (end < start) ? start : end;

    vec.clear();
    for (int i = 0; i < actual_end; ++i) {
        if (i >= 10) {
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
