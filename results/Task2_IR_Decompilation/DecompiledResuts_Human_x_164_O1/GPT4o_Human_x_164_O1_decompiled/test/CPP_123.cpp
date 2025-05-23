#include <vector>
#include <stdexcept>
#include <memory>
#include <iostream>

void get_odd_collatz(std::vector<int> &vec, int n) {
    if (n < 1) return;

    vec.reserve(n); // Ensure we have enough space
    int count = 0;

    while (n != 1) {
        vec.push_back(n);
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        count++;
    }
    vec.push_back(1);
}

int main() {
    std::vector<int> collatz_sequence;
    get_odd_collatz(collatz_sequence, 7); // Example starting number

    for (int number : collatz_sequence) {
        std::cout << number << " ";
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
    assert (issame(get_odd_collatz(14) , {1, 5, 7, 11, 13, 17}));
    assert (issame(get_odd_collatz(5) , {1, 5}));
    assert (issame(get_odd_collatz(12) , {1, 3, 5}));
    assert (issame(get_odd_collatz(1) , {1}));
}
