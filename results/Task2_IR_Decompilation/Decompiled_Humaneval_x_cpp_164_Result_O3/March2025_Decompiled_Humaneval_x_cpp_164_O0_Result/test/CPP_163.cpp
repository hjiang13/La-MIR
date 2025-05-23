#include <vector>
#include <stdexcept>
#include <algorithm>

std::vector<int> generate_integers(int start, int end) {
    if (end < start) {
        std::swap(start, end);
    }
    std::vector<int> result;
    for (int i = start; i <= end; ++i) {
        if (i < 10 && i % 2 == 0) {
            result.push_back(i);
        }
    }
    return result;
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
