```cpp
#include <vector>
#include <stdexcept>
#include <cstring>
#include <algorithm>

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

void maximum(std::vector<int>& result, const std::vector<int>& vec, int size) {
    if (size < 0) {
        throw_length_error("cannot create std::vector larger than max_size()");
    }

    result.clear();
    if (size == 0) {
        return;
    }

    int* new_data = new int[size];
    std::memcpy(new_data, vec.data(), size * sizeof(int));
    result.assign(new_data, new_data + size);
    delete[] new_data;
}

void introsort_loop(int* begin, int* end, int size) {
    if (size > 64) {
        std::sort(begin, end);
    } else {
        std::stable_sort(begin, end);
    }
}

void final_insertion_sort(int* begin, int* end) {
    if (begin == end) return;
    
    for (int* i = begin + 1; i < end; ++i) {
        int value = *i;
        int* j = i - 1;
        while (j >= begin && *j > value) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = value;
    }
}

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    std::vector<int> result;
    maximum(result, vec, vec.size());
    return 0;
}
```