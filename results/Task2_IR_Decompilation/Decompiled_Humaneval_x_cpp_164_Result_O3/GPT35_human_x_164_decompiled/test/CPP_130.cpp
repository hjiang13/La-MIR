```c
#include <vector>
#include <iostream>

void tr(std::vector<int>& v, int n) {
    if (n == 0) {
        v.clear();
    } else if (n < 2) {
        if (n == 1) {
            v.push_back(1);
        }
    } else {
        int prev = 1;
        int curr = 1;
        v.push_back(prev);
        v.push_back(curr);
        for (int i = 2; i < n; i++) {
            int next = prev + curr;
            v.push_back(next);
            prev = curr;
            curr = next;
        }
    }
}

int main() {
    std::vector<int> fib;
    tr(fib, 10);
    for (int i : fib) {
        std::cout << i << " ";
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
    assert (issame(tri(3) , {1, 3, 2, 8}));
    assert (issame(tri(4) , {1, 3, 2, 8, 3}));
    assert (issame(tri(5) , {1, 3, 2, 8, 3, 15}));
    assert (issame(tri(6) , {1, 3, 2, 8, 3, 15, 4}));
    assert (issame(tri(7) , {1, 3, 2, 8, 3, 15, 4, 24}));
    assert (issame(tri(8) , {1, 3, 2, 8, 3, 15, 4, 24, 5}));
    assert (issame(tri(9) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35}));
    assert (issame(tri(20) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11}));
    assert (issame(tri(0) , {1}));
    assert (issame(tri(1) , {1, 3}));
}
