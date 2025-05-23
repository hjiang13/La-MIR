#include <vector>

struct _Vector_base {
    struct _Vector_impl {
        struct _Vector_impl_data {
            int* a;
            int* b;
            int* c;
        };
    };
};

void eat(std::vector<_Vector_base>* v, int x, int y, int z) {
    if (z < y) {
        char* ptr = reinterpret_cast<char*>(v);
        memset(ptr, 0, 24);
        char* newPtr = reinterpret_cast<char*>(operator new(8));
        if (newPtr) {
            int* intPtr = reinterpret_cast<int*>(newPtr);
            *(reinterpret_cast<char**>(v)) = newPtr;
            char* ptr2 = newPtr + 8;
            *(reinterpret_cast<int**>(reinterpret_cast<int**>(reinterpret_cast<char*>(v) + 0) + 0) + 0) = reinterpret_cast<int*>(ptr2);
            *intPtr = z + x;
        }
    } else {
        int diff = z - y;
        int sum = y + x;
        char* ptr = reinterpret_cast<char*>(v);
        memset(ptr, 0, 24);
        char* newPtr = reinterpret_cast<char*>(operator new(8));
        if (newPtr) {
            int* intPtr = reinterpret_cast<int*>(newPtr);
            *(reinterpret_cast<char**>(v)) = newPtr;
            char* ptr2 = newPtr + 8;
            *(reinterpret_cast<int**>(reinterpret_cast<int**>(reinterpret_cast<char*>(v) + 0) + 0) + 0) = reinterpret_cast<int*>(ptr2);
            *intPtr = sum;
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
    assert (issame(eat(5, 6, 10) , {11, 4}));
    assert (issame(eat(4, 8, 9) , {12, 1}));
    assert (issame(eat(1, 10, 10) , {11, 0}));
    assert (issame(eat(2, 11, 5) , {7, 0}));
    
    assert (issame(eat(4, 5, 7) , {9, 2}));
    assert (issame(eat(4, 5, 1) , {5, 0}));
}
