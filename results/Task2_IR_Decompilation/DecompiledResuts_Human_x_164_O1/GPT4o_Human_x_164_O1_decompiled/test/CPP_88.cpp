#include <vector>
#include <iostream>
#include <cstdlib>

void introsort_loop(int* first, int* last, long depthLimit);
void final_insertion_sort(int* first, int* last);
void realloc_insert(std::vector<int>& vec, int* position, int* element);

void sort_array(std::vector<int>& vec) {
    if (vec.empty()) {
        vec.clear();
        return;
    }

    int* data = vec.data();
    int size = vec.size();

    if (size < 2) {
        return;
    }

    introsort_loop(data, data + size, 2 * log(size));
    final_insertion_sort(data, data + size);
}

void introsort_loop(int* first, int* last, long depthLimit) {
    // Implementation of introsort loop algorithm
    // ...
}

void final_insertion_sort(int* first, int* last) {
    // Implementation of final insertion sort algorithm
    // ...
}

void realloc_insert(std::vector<int>& vec, int* position, int* element) {
    // Implementation of realloc insert logic
    // ...
}

int main() {
    std::vector<int> vec = {4, 3, 2, 1};
    sort_array(vec);

    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

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
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({5}) , {5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5}) , {0, 1, 2, 3, 4, 5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5, 6}) , {6, 5, 4, 3, 2, 1, 0}));
    assert (issame(sort_array({2, 1}) , {1, 2}));
    assert (issame(sort_array({15, 42, 87, 32 ,11, 0}) , {0, 11, 15, 32, 42, 87}));
    assert (issame(sort_array({21, 14, 23, 11}) , {23, 21, 14, 11}));
}
