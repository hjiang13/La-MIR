```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void __throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void sort_third(std::vector<int>& vec1, const std::vector<int>& vec2) {
    int* begin1 = vec1.data();
    int* end1 = begin1 + vec1.size();
    int* begin2 = const_cast<int*>(vec2.data());
    int* end2 = begin2 + vec2.size();

    if (begin1 == end1 || begin2 == end2) {
        return;
    }

    if (end1 - begin1 + 1 < 0) {
        __throw_length_error("vector::_M_realloc_insert");
    }

    int* temp = new int[(end1 - begin1) + (end2 - begin2)];
    std::memcpy(temp, begin1, (end1 - begin1) * sizeof(int));
    std::memcpy(temp + (end1 - begin1), begin2, (end2 - begin2) * sizeof(int));

    delete[] begin1;

    vec1.assign(temp, temp + (end1 - begin1 + end2 - begin2));
    delete[] temp;
}

void __introsort_loop(int* begin, int* end, std::ptrdiff_t depth_limit) {
    // Implementation of introsort algorithm
}

void __final_insertion_sort(int* begin, int* end) {
    // Implementation of final insertion sort
}

int main() {
    std::vector<int> vec1 = { /* your data here */ };
    std::vector<int> vec2 = { /* your data here */ };
    sort_third(vec1, vec2);
    return 0;
}
```