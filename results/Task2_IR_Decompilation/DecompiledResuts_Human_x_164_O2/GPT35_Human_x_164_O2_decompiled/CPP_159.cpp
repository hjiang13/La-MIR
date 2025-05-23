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
```