#include <vector>
#include <stdexcept>
#include <cstring>

void sort_even(std::vector<float>& vec1, const std::vector<float>& vec2) {
    float* data1 = vec1.data();
    float* data2 = vec2.data();

    if (data1 == data2) return;

    size_t size1 = vec1.size();
    size_t size2 = vec2.size();
    if (size1 == 0) return;

    float* temp = nullptr;
    if (size2 < size1) {
        temp = new float[size1];
    } else {
        throw std::length_error("vector::_M_realloc_insert");
    }

    std::memcpy(temp, data1, size1 * sizeof(float));

    for (size_t i = 0; i < size1; ++i) {
        if (data2[i] < temp[i]) {
            std::swap(temp[i], data2[i]);
        }
    }

    std::memcpy(data1, temp, size1 * sizeof(float));

    delete[] temp;
}

void insertion_sort(float* first, float* last) {
    for (float* i = first + 1; i < last; ++i) {
        float key = *i;
        float* j = i - 1;
        while (j >= first && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

void make_heap(float* first, float* last) {
    for (float* i = first; i < last; ++i) {
        insertion_sort(first, last);
    }
}

int main() {
    std::vector<float> vec1 = {3.0, 1.0, 4.0, 1.5};
    std::vector<float> vec2 = {2.0, 5.0, 6.5};

    sort_even(vec1, vec2);

    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(sort_even({1, 2, 3}), {1, 2, 3}));
    assert (issame(sort_even({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}) , {-10, 3, -5, 2, -3, 3, 5, 0, 9, 1, 123}));
    assert (issame(sort_even({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}) , {-12, 8, 3, 4, 5, 2, 12, 11, 23, -10}));
}
