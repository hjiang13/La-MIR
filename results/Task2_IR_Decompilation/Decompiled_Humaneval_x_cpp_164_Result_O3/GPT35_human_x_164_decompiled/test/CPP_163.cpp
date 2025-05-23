```c++
#include <vector>

void generate_integers(std::vector<int>& vec, int start, int end) {
    int size = end < start ? start : end;
    int capacity = end < start ? end : start;
    
    vec._M_impl._M_start = new int[size];
    vec._M_impl._M_finish = vec._M_impl._M_start;
    vec._M_impl._M_end_of_storage = vec._M_impl._M_start + size;
    
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            vec.push_back(i);
        }
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
