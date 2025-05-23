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
```