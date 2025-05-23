#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> get_odd_collatz(int n) {
    std::vector<int> result{1};
    while (n != 1) {
        if (n % 2 == 1) {
            result.push_back(n);
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
    }
    std::sort(result.begin(), result.end());
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
    assert (issame(get_odd_collatz(14) , {1, 5, 7, 11, 13, 17}));
    assert (issame(get_odd_collatz(5) , {1, 5}));
    assert (issame(get_odd_collatz(12) , {1, 3, 5}));
    assert (issame(get_odd_collatz(1) , {1}));
}
