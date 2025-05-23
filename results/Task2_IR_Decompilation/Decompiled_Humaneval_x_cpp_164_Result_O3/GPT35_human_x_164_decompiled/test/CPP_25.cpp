#include <vector>
#include <stdexcept>

void factorize(std::vector<int>& vec, int num) {
    if (num < 4) {
        vec.clear();
        return;
    }

    int div = 2;
    while (num % div != 0) {
        div++;
    }

    vec.push_back(div);
    factorize(vec, num / div);
}

int main() {
    std::vector<int> factors;
    int number = 123456; // Specify the number to factorize here
    factorize(factors, number);

    for (int factor : factors) {
        printf("%d ", factor);
    }

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
