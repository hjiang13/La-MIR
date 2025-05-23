#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstring>

void introsort_loop(int* begin, int* end, long size);
void final_insertion_sort(int* begin, int* end);
void throw_length_error(const char* msg);

void maximum(std::vector<int>& result, const std::vector<int>& input, int size) {
    int* first = input.data();
    int* last = first + size;

    if (first == last) {
        throw_length_error("cannot create std::vector larger than max_size()");
    }

    int* storage = new int[size];

    std::memset(storage, 0, sizeof(int) * size);
    
    if (size < 1) {
        result.assign(storage, storage + size);
        delete[] storage;
        return;
    }

    std::memcpy(storage, first, sizeof(int) * size);
    result.assign(storage, storage + size);

    delete[] storage;
}

void introsort_loop(int* begin, int* end, long size) {
    if (end - begin > 64) {
        long length = end - begin;
        long mid = length / 2;
        introsort_loop(begin, begin + mid, mid);
        introsort_loop(begin + mid, end, length - mid);
    } else {
        final_insertion_sort(begin, end);
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

void throw_length_error(const char* msg) {
    throw std::length_error(msg);
}

int main() {
    std::vector<int> result;
    std::vector<int> input = {5, 3, 8, 1, 2};
    try {
        maximum(result, input, input.size());
        for (int value : result) {
            std::cout << value << " ";
        }
    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }
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
