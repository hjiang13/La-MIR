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
    assert (issame(maximum({-3, -4, 5}, 3) , {-4, -3, 5}));
    assert (issame(maximum({4, -4, 4}, 2) , {4, 4}));
    assert (issame(maximum({-3, 2, 1, 2, -1, -2, 1}, 1) , {2}));
    assert (issame(maximum({123, -123, 20, 0 , 1, 2, -3}, 3) , {2, 20, 123}));
    assert (issame(maximum({-123, 20, 0 , 1, 2, -3}, 4) , {0, 1, 2, 20}));
    assert (issame(maximum({5, 15, 0, 3, -13, -8, 0}, 7) , {-13, -8, 0, 0, 3, 5, 15}));
    assert (issame(maximum({-1, 0, 2, 5, 3, -10}, 2) , {3, 5}));
    assert (issame(maximum({1, 0, 5, -7}, 1) , {5}));
    assert (issame(maximum({4, -4}, 2) , {-4, 4}));
    assert (issame(maximum({-10, 10}, 2) , {-10, 10}));
    assert (issame(maximum({1, 2, 3, -23, 243, -400, 0}, 0) , {}));
}
