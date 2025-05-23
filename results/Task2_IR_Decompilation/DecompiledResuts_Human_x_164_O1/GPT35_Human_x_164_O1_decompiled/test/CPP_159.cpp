```cpp
#include <vector>

struct _Vector_base {
    struct _Vector_impl {
        struct _Vector_impl_data {
            int* first;
            int* last;
            int* end;
        };
    };
};

void eat(std::vector<int>& v, int arg1, int arg2, int arg3) {
    if (arg3 < arg2) {
        char* ptr = reinterpret_cast<char*>(&v);
        memset(ptr, 0, 24);

        if (arg3 == arg1) {
            return;
        }

        char* new_ptr = reinterpret_cast<char*>(new char[8]);
        *reinterpret_cast<char**>(&v) = new_ptr;

        char* data_ptr = reinterpret_cast<char*>(new_ptr + 8);
        *reinterpret_cast<char**>(&v[0].first) = data_ptr;

        v[0].last = arg1 + arg3;
        *reinterpret_cast<int*>(data_ptr) = arg1;

        return;
    } else {
        char* ptr = reinterpret_cast<char*>(&v);
        memset(ptr, 0, 24);

        if (arg3 == arg2) {
            return;
        }

        char* new_ptr = reinterpret_cast<char*>(new char[8]);
        *reinterpret_cast<char**>(&v) = new_ptr;

        char* data_ptr = reinterpret_cast<char*>(new_ptr + 8);
        *reinterpret_cast<char**>(&v[0].first) = data_ptr;

        v[0].last = arg2 + arg1;
        *reinterpret_cast<int*>(data_ptr) = arg2;

        return;
    }
}

int main() {
    std::vector<int> v;
    eat(v, 1, 2, 3);

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
    assert (issame(eat(5, 6, 10) , {11, 4}));
    assert (issame(eat(4, 8, 9) , {12, 1}));
    assert (issame(eat(1, 10, 10) , {11, 0}));
    assert (issame(eat(2, 11, 5) , {7, 0}));
    
    assert (issame(eat(4, 5, 7) , {9, 2}));
    assert (issame(eat(4, 5, 1) , {5, 0}));
}
