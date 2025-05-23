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

void memmove_custom(void* dest, const void* src, size_t n) {
    std::memmove(dest, src, n);
}

void memset_custom(void* s, int c, size_t n) {
    std::memset(s, c, n);
}

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    if (input.empty()) {
        result.clear();
        return;
    }

    size_t input_size = input.size();
    size_t required_size = ((input_size - 1) * 2) + 1; 
    if (required_size < input_size) throw_length_error("vector::_M_realloc_insert");
    
    result.resize(required_size);
    for (size_t i = 0; i < input_size; ++i) {
        result[i * 2] = input[i];
        if (i < input_size - 1) {
            result[i * 2 + 1] = value;
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
    assert (issame(intersperse({}, 7), {}));
    
    assert (issame(intersperse({5, 6, 3, 2}, 8),{5, 8, 6, 8, 3, 8, 2}));
    assert (issame(intersperse({2, 2, 2}, 2),{2, 2, 2, 2, 2}));
}