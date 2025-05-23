```cpp
#include <vector>
#include <algorithm>

void get_odd_collatzi(std::vector<int>& vec, int n) {
    vec.clear();
    
    if (n == 1) {
        vec.push_back(1);
        return;
    }
    
    int num = n;
    while (num != 1) {
        if (num % 2 == 1) {
            vec.push_back(num);
            num = 3 * num + 1;
        } else {
            num /= 2;
        }
    }
    
    vec.push_back(1);
}

int main() {
    std::vector<int> collatz_sequence;
    int input = 27; // example input
    get_odd_collatzi(collatz_sequence, input);
    
    // Print the Collatz sequence
    for (int num : collatz_sequence) {
        std::cout << num << " ";
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
    assert (issame(get_odd_collatz(14) , {1, 5, 7, 11, 13, 17}));
    assert (issame(get_odd_collatz(5) , {1, 5}));
    assert (issame(get_odd_collatz(12) , {1, 3, 5}));
    assert (issame(get_odd_collatz(1) , {1}));
}
