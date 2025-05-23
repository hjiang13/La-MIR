#include <vector>
#include <stdexcept>

void get_odd_collatz(std::vector<int>& vec, int n) {
    vec.clear();
    vec.reserve(4);
    vec.push_back(1);
    vec.push_back(1);
    
    if (n == 1) {
        return;
    }
    
    while (true) {
        int index = vec.size();
        int rem = n % 2;
        int div = n / 2;
        
        if (rem == 1) {
            vec.push_back(n);
            n = 3 * n + 1;
        } else {
            vec.push_back(n);
            n = div;
        }
        
        if (index >= vec.capacity()) {
            throw std::length_error("vector::_M_realloc_insert");
        }

        if (n == 1) {
            break;
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
    assert (issame(get_odd_collatz(14) , {1, 5, 7, 11, 13, 17}));
    assert (issame(get_odd_collatz(5) , {1, 5}));
    assert (issame(get_odd_collatz(12) , {1, 3, 5}));
    assert (issame(get_odd_collatz(1) , {1}));
}
