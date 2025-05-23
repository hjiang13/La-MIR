#include <vector>

struct _Vector_base {
    struct _Vector_base_impl {
        int* _M_start;
        int* _M_finish;
        int* _M_end_of_storage;
    };
};

void make_a_pile(std::vector<int>& v, int size) {
    char* ptr = reinterpret_cast<char*>(&v);
    __builtin_memset(ptr, 0, 24);
    char* data = reinterpret_cast<char*>(operator new(4));
    int* data_ptr = reinterpret_cast<int*>(data);
    v._M_impl._M_start = data_ptr;
    char* tmp = data + 4;
    char* new_data = reinterpret_cast<char*>(v._M_impl._M_start);
    v._M_impl._M_finish = reinterpret_cast<int*>(tmp);
    *data_ptr = size;
    v._M_impl._M_end_of_storage = reinterpret_cast<int*>(tmp);
    if (size > 1) {
        int* end = v._M_impl._M_end_of_storage;
        int* start = v._M_impl._M_start;
        int* finish = v._M_impl._M_finish;
        int count = 1;
        ptrdiff_t diff = end - start;
        ptrdiff_t count2 = diff >> 2;
        ptrdiff_t new_size = count2 - 1;
        int* ptr = start + new_size;
        int value = *ptr + 2;
        if (ptr == finish) {
            *ptr = value;
            int* new_finish = ptr + 1;
            v._M_impl._M_start = new_finish;
            return;
        }
        else {
            bool cond1 = (diff == 9223372036854775804);
            if (cond1) {
                throw_length_error("vector::_M_realloc_insert");
                return;
            }
            bool cond2 = (diff == 0);
            ptrdiff_t new_size2 = cond2 ? 1 : new_size + count2;
            bool cond3 = (new_size2 < count2) || (new_size2 > 2305843009213693951);
            ptrdiff_t new_size3 = cond3 ? 2305843009213693951 : new_size2;
            bool cond4 = (new_size3 == 0);
            if (cond4) {
                throw_length_error("vector::_M_realloc_insert");
                return;
            }
            ptrdiff_t new_size4 = new_size3 << 2;
            char* new_data2 = reinterpret_cast<char*>(operator new(new_size4));
            int* new_ptr = reinterpret_cast<int*>(new_data2);
            int* new_ptr2 = reinterpret_cast<int*>(v._M_impl._M_start);
            *new_ptr = value;
            bool cond5 = (diff > 0);
            if (cond5) {
                char* old_ptr = reinterpret_cast<char*>(new_ptr);
                char* old_ptr2 = reinterpret_cast<char*>(start);
                __builtin_memmove(old_ptr, old_ptr2, diff, 0);
            }
            char* old_ptr3 = reinterpret_cast<char*>(start);
            operator delete(old_ptr3);
            v._M_impl._M_start = new_ptr;
            v._M_impl._M_finish = new_ptr + 1;
            v._M_impl._M_end_of_storage = new_ptr + new_size3;
        }
    }
}

int main() {
    std::vector<int> v;
    make_a_pile(v, 5);
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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}
