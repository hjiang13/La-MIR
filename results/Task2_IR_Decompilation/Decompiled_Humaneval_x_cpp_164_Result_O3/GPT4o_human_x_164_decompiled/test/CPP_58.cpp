#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <iostream>

void common(std::vector<int>& v1, const std::vector<int>& v2, const std::vector<int>& v3) {
    int* v1_data = v1.data();
    const int* v2_data = v2.data();
    const int* v3_data = v3.data();

    if (v1_data == nullptr) {
        v1.resize(v2.size() + v3.size());
        v1_data = v1.data();
    }

    int* end_v1 = v1_data + v1.size();
    int* end_v2 = const_cast<int*>(v2_data + v2.size());
    int* end_v3 = const_cast<int*>(v3_data + v3.size());

    if (end_v1 == end_v2) {
        return;
    }
    
    if (end_v1 == end_v3) {
        return;
    }

    std::vector<int> tmp(v1.size() + v2.size() + v3.size());
    auto it = std::set_intersection(v2.begin(), v2.end(), v3.begin(), v3.end(), tmp.begin());
    std::copy(tmp.begin(), it, v1_data);
}

void introsort(int* begin, int* end) {
    // Implementation of introsort
}

void insertion_sort(int* begin, int* end) {
    // Implementation of insertion sort
}

void make_heap(int* begin, int* end) {
    // Implementation of heap creation
}

int main() {
    std::vector<int> vec1, vec2, vec3;
    // Initialize vec1, vec2, vec3
    common(vec1, vec2, vec3);
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
    assert (issame(common({1, 4, 3, 34, 653, 2, 5}, {5, 7, 1, 5, 9, 653, 121}) , {1, 5, 653}));
    assert (issame(common({5, 3, 2, 8}, {3, 2}) , {2, 3}));
    assert (issame(common({4, 3, 2, 8}, {3, 2, 4}) , {2, 3, 4}));
    assert (issame(common({4, 3, 2, 8}, {}) , {}));
}
