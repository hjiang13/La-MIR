```cpp
#include <vector>

struct _Vector_base {
    struct _Vector_impl {
        struct _Vector_impl_data {
            int* ptr1;
            int* ptr2;
            int* ptr3;
        };
    };
};

void eat(std::vector<int>& vec, int arg1, int arg2, int arg3) {
    if (arg3 < arg2) {
        memset((void*)&vec, 0, sizeof(std::vector<int>));
        void* ptr = operator new(8);
        if (ptr) {
            int sum = arg3 + arg1;
            int* int_ptr = static_cast<int*>(ptr);
            void** vec_ptr = reinterpret_cast<void**>(&vec);
            *vec_ptr = ptr;
            void* ptr2 = static_cast<void*>(static_cast<char*>(ptr) + 8);
            void** vec_ptr2 = reinterpret_cast<void**>(&vec[0][0][0][2]);
            *vec_ptr2 = ptr2;
            *int_ptr = sum;
        }
    } else {
        int diff = arg3 - arg2;
        int sum2 = arg2 + arg1;
        void* ptr = operator new(8);
        if (ptr) {
            int* int_ptr = static_cast<int*>(ptr);
            void** vec_ptr = reinterpret_cast<void**>(&vec);
            *vec_ptr = ptr;
            void* ptr2 = static_cast<void*>(static_cast<char*>(ptr) + 8);
            void** vec_ptr2 = reinterpret_cast<void**>(&vec[0][0][0][2]);
            *vec_ptr2 = ptr2;
            *int_ptr = sum2;
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
