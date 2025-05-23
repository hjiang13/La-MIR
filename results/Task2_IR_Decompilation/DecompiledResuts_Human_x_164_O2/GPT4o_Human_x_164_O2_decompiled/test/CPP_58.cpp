#include <vector>
#include <stdexcept>
#include <cstring>

void common(std::vector<int>& v0, const std::vector<int>& v1, const std::vector<int>& v2) {
    int* data0 = v0.data();
    int* data1 = v1.data();
    int* data2 = v2.data();
    int* end0 = data0 + v0.size();
    int* end1 = data1 + v1.size();
    
    std::memset(data0, 0, sizeof(int) * 24);
    
    if (data0 == data1) {
        return;
    }

    while (end0 - data0 > 15) {
        int* mid = data0 + (end0 - data0) / 2;
        if (*mid < *data1) {
            end0 = mid;
        } else {
            end0 = mid + 1;
        }
    }

    for (int* ptr = data0; ptr < end0; ++ptr) {
        if (*ptr == *data1) {
            return;
        }
    }

    int* new_data = new int[v0.size() + 1];
    std::memcpy(new_data, data0, (end0 - data0) * sizeof(int));
    new_data[end0 - data0] = *data1;
    std::memcpy(new_data + (end0 - data0) + 1, end0, (data0 + v0.size() - end0) * sizeof(int));
    
    v0 = std::vector<int>(new_data, new_data + v0.size() + 1);
    delete[] new_data;
}

void realloc_insert(std::vector<int>& v, int* position, int* value) {
    size_t old_size = v.size();
    size_t new_size = old_size + 1;
    if (new_size > old_size) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    
    int* new_data = new int[new_size];
    std::memcpy(new_data, v.data(), (position - v.data()) * sizeof(int));
    new_data[position - v.data()] = *value;
    std::memcpy(new_data + (position - v.data()) + 1, position, (old_size - (position - v.data())) * sizeof(int));
    
    v = std::vector<int>(new_data, new_data + new_size);
    delete[] new_data;
}

void introsort(int* begin, int* end, size_t size) {
    if (size <= 64) {
        for (int* i = begin; i < end; ++i) {
            for (int* j = i; j > begin && *j < *(j - 1); --j) {
                std::swap(*j, *(j - 1));
            }
        }
    } else {
        int* mid = begin + (end - begin) / 2;
        introsort(begin, mid, size / 2);
        introsort(mid, end, size / 2);
    }
}

void final_insertion_sort(int* begin, int* end) {
    for (int* i = begin + 1; i < end; ++i) {
        int key = *i;
        int* j = i - 1;
        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
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
    assert (issame(common({1, 4, 3, 34, 653, 2, 5}, {5, 7, 1, 5, 9, 653, 121}) , {1, 5, 653}));
    assert (issame(common({5, 3, 2, 8}, {3, 2}) , {2, 3}));
    assert (issame(common({4, 3, 2, 8}, {3, 2, 4}) , {2, 3, 4}));
    assert (issame(common({4, 3, 2, 8}, {}) , {}));
}
