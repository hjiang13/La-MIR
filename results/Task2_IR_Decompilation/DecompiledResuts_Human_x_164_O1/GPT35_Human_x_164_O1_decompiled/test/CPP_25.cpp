```cpp
#include <vector>

void factorize(std::vector<int>& result, int num) {
    result.clear();
    
    if (num < 4) {
        result.push_back(num);
        return;
    }
    
    int divisor = 2;
    while (num % divisor != 0) {
        divisor++;
    }
    
    result.push_back(divisor);
    factorize(result, num / divisor);
}

int main() {
    std::vector<int> result;
    factorize(result, 100); // Change the number here for factorization
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
