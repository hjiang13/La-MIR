#include <vector>
#include <stdexcept>
#include <cstring>

void get_odd_collatz(std::vector<int>& vec, int n) {
    vec.clear();
    vec.reserve(4);
    vec.push_back(1);
    vec.push_back(nullptr);
    
    if (n == 1) {
        return;
    }

    int* current = nullptr;
    int* prev = nullptr;
    int* next = nullptr;

    while (true) {
        if (n == 1) {
            break;
        }

        int remainder = n % 2;
        int half = n / 2;

        if (remainder == 1) {
            current = vec.data() + vec.size();
            vec.push_back(n);
            n = 3 * n + 1;
        } else {
            if (vec.size() < 2) {
                throw std::length_error("vector::_M_realloc_insert");
            }
            prev = vec.data() + vec.size() - 1;
            next = current;
            *next = *prev;
            current = next + 1;
            vec.push_back(n);
            n = half;
        }

        if (n == 0) {
            break;
        }
    }

    vec.push_back(0);
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
