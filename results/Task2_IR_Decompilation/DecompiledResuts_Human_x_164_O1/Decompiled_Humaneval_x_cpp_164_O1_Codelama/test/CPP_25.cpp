#include <iostream>
#include <vector>

using namespace std;

class vector {
public:
    struct _Vector_base {
        struct _Vector_impl {
            int* _M_start;
            int* _M_finish;
            int* _M_end_of_storage;
        } _M_impl;
    } _M_start;

    vector() {
        _M_start._M_impl._M_start = nullptr;
        _M_start._M_impl._M_finish = nullptr;
        _M_start._M_impl._M_end_of_storage = nullptr;
    }

    void _M_realloc_insert(int* position, int value) {
        int* new_start = new int[2 * (_M_start._M_impl._M_finish - _M_start._M_impl._M_start)];
        int* new_finish = new_start;
        for (int* i = _M_start._M_impl._M_start; i != position; ++i) {
            *new_finish++ = *i;
        }
        *new_finish++ = value;
        for (int* i = position; i != _M_start._M_impl._M_finish; ++i) {
            *new_finish++ = *i;
        }
        delete[] _M_start._M_impl._M_start;
        _M_start._M_impl._M_start = new_start;
        _M_start._M_impl._M_finish = new_finish;
        _M_start._M_impl._M_end_of_storage = new_start + 2 * (_M_start._M_impl._M_finish - _M_start._M_impl._M_start);
    }
};

int factorize(int n) {
    vector v;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            v._M_realloc_insert(v._M_start._M_impl._M_finish, i);
            n /= i;
            i = 1;
        }
    }
    return v._M_start._M_impl._M_finish - v._M_start._M_impl._M_start;
}

int main() {
    int n;
    cin >> n;
    cout << factorize(n) << endl;
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
