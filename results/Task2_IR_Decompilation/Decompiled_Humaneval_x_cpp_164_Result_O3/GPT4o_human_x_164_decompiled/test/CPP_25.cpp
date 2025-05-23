#include <vector>
#include <stdexcept>
#include <cstring>

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void factorize(std::vector<int>& vec, int value) {
    int* old_data = nullptr;
    int* new_data = nullptr;
    size_t old_size = 0;
    size_t new_size = 0;

    if (value < 4) {
        vec.clear();
        vec.resize(1);
        vec[0] = value;
        return;
    }

    old_size = vec.size();
    new_size = old_size > 0 ? old_size : 1;

    while (true) {
        if (old_size == new_size) {
            if (new_size > 2305843009213693951 / 4) {
                throw_length_error("vector::_M_realloc_insert");
            }
            new_size *= 2;
            new_data = new int[new_size];
            std::memmove(new_data, vec.data(), old_size * sizeof(int));
            delete[] old_data;
            old_data = new_data;
        }

        old_data[old_size++] = value;

        if (old_size > new_size) {
            throw_length_error("vector::_M_realloc_insert");
        }
        
        vec.resize(old_size);
        std::memcpy(vec.data(), old_data, old_size * sizeof(int));

        if (old_size > value) break;
    }

    delete[] old_data;
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
