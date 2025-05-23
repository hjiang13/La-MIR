#include <vector>
#include <iostream>

void factorize(std::vector<int>& vec, int n) {
    vec.clear();
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            vec.push_back(i);
        }
    }
}

int main() {
    std::vector<int> factors;
    int number = 12; // Example number
    factorize(factors, number);
    
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;

    return 0;
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
