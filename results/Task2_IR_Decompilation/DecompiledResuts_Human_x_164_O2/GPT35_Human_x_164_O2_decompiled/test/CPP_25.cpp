```cpp
#include <vector>
#include <stdexcept>

void factorize(std::vector<int>& vec, int num) {
    if (num < 4) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int div = 2;
    while (num % div != 0) {
        div++;
    }

    if (div == num) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    vec.push_back(div);
    num /= div;

    while (num > 1) {
        div = 2;
        while (num % div != 0) {
            div++;
        }

        vec.push_back(div);
        num /= div;
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
    assert (issame(factorize(2) , {2}));
    assert (issame(factorize(4) , {2, 2}));
    assert (issame(factorize(8) , {2, 2, 2}));
     assert (issame(factorize(3 * 19) , {3, 19}));
    assert (issame(factorize(3 * 19 * 3 * 19) , {3, 3, 19, 19})); 
    assert (issame(factorize(3 * 19 * 3 * 19 * 3 * 19) , {3, 3, 3, 19, 19, 19})); 
    assert (issame(factorize(3 * 19 * 19 * 19) , {3, 19, 19, 19})); 
    assert (issame(factorize(3 * 2 * 3) , {2, 3, 3}));
}
