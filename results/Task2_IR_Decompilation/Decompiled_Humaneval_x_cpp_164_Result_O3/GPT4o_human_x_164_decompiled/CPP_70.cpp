```cpp
#include <vector>
#include <stdexcept>
#include <cstring>
#include <algorithm>

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void strange_sort_list(std::vector<int>& vec1, const std::vector<int>& vec2) {
    if (&vec1 == &vec2) {
        return;
    }
    
    std::vector<int> temp;
    temp.reserve(vec1.size() + vec2.size());
    
    auto it1 = vec1.begin();
    auto it2 = vec2.begin();
    
    while (it1 != vec1.end() && it2 != vec2.end()) {
        if (*it1 < *it2) {
            temp.push_back(*it1++);
        } else {
            temp.push_back(*it2++);
        }
    }
    
    while (it1 != vec1.end()) {
        temp.push_back(*it1++);
    }
    
    while (it2 != vec2.end()) {
        temp.push_back(*it2++);
    }
    
    vec1 = std::move(temp);
}

void insertion_sort(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i - 1;
        while (j < vec.size() && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void make_heap(std::vector<int>& vec) {
    std::make_heap(vec.begin(), vec.end());
}

void final_insertion_sort(std::vector<int>& vec) {
    insertion_sort(vec);
}

void introsort_helper(std::vector<int>& vec, size_t size) {
    if (size <= 64) {
        final_insertion_sort(vec);
    } else {
        make_heap(vec);
    }
}

void strange_sort(std::vector<int>& vec) {
    if (vec.empty()) {
        throw_length_error("vector::_M_realloc_insert");
    }
    
    introsort_helper(vec, vec.size());
}
```