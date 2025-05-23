#include <vector>

void incr_list(std::vector<int>& sret, std::vector<int>& vec) {
    int* data = reinterpret_cast<int*>(&sret);
    *data = reinterpret_cast<int>(&sret);
    int idx = 0;
    while (idx < vec.size()) {
        int* elem = &vec[idx];
        *elem += 1;
        idx++;
    }
}

int size(std::vector<int>& vec) {
    std::_Vector_base<int, std::allocator<int>>::_Vector_impl* base = reinterpret_cast<std::_Vector_base<int, std::allocator<int>>::_Vector_impl*>(&vec);
    std::_Vector_base<int, std::allocator<int>>::_Vector_impl_data* data = &base->data;
    int* begin = data->begin;
    int* end = data->end;
    return (end - begin) / sizeof(int);
}

int* get_element(std::vector<int>& vec, int idx) {
    std::_Vector_base<int, std::allocator<int>>::_Vector_impl* base = reinterpret_cast<std::_Vector_base<int, std::allocator<int>>::_Vector_impl*>(&vec);
    std::_Vector_base<int, std::allocator<int>>::_Vector_impl_data* data = &base->data;
    int* begin = data->begin;
    return &begin[idx];
}

void move(std::vector<int>& dest, std::vector<int>& src) {
    std::_Vector_base<int, std::allocator<int>>::_Vector_impl* base_dest = reinterpret_cast<std::_Vector_base<int, std::allocator<int>>::_Vector_impl*>(&dest);
    std::_Vector_base<int, std::allocator<int>>::_Vector_impl* base_src = reinterpret_cast<std::_Vector_base<int, std::allocator<int>>::_Vector_impl*>(&src);
    std::_Vector_base<int, std::allocator<int>>::_Vector_impl_data* data_dest = &base_dest->data;
    std::_Vector_base<int, std::allocator<int>>::_Vector_impl_data* data_src = &base_src->data;
    std::allocator<int>* alloc_dest = reinterpret_cast<std::allocator<int>*>(&data_dest->alloc);
    std::allocator<int>* alloc_src = reinterpret_cast<std::allocator<int>*>(&data_src->alloc);
    *alloc_dest = *alloc_src;
    data_dest->begin = data_src->begin;
    data_dest->end = data_src->end;
    data_dest->cap = data_src->cap;
    data_src->begin = nullptr;
    data_src->end = nullptr;
    data_src->cap = nullptr;
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
    assert (issame(incr_list({}) , {}));
    assert (issame(incr_list({3, 2, 1}) , {4, 3, 2}));
    assert (issame(incr_list({5, 2, 5, 2, 3, 3, 9, 0, 123}) , {6, 3, 6, 3, 4, 4, 10, 1, 124}));
}
