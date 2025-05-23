#include <vector>
#include <stdexcept>
#include <cstring>

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void* allocate_memory(size_t size) {
    return operator new(size);
}

void deallocate_memory(void* ptr) {
    operator delete(ptr);
}

void factorize(std::vector<int>& v, int n) {
    int* old_data = nullptr;
    int* new_data = nullptr;
    size_t old_size = v.size();
    size_t new_size = 0;

    if (n < 4) {
        v.resize(0);
        return;
    }

    while (true) {
        int factor = n / 2;
        if (n % 2 == 0) {
            v.push_back(2);
            n /= 2;
        } else {
            if (n == 1) break;
            for (int i = 3; i * i <= n; i += 2) {
                while (n % i == 0) {
                    v.push_back(i);
                    n /= i;
                }
            }
            if (n > 1) {
                v.push_back(n);
            }
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
    assert (issame(factorize(2) , {2}));
    assert (issame(factorize(4) , {2, 2}));
    assert (issame(factorize(8) , {2, 2, 2}));
     assert (issame(factorize(3 * 19) , {3, 19}));
    assert (issame(factorize(3 * 19 * 3 * 19) , {3, 3, 19, 19})); 
    assert (issame(factorize(3 * 19 * 3 * 19 * 3 * 19) , {3, 3, 3, 19, 19, 19})); 
    assert (issame(factorize(3 * 19 * 19 * 19) , {3, 19, 19, 19})); 
    assert (issame(factorize(3 * 2 * 3) , {2, 3, 3}));
}
