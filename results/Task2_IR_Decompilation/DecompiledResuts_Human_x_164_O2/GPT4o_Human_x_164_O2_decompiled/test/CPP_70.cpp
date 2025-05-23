#include <vector>
#include <iostream>
#include <algorithm>

void introsort_loop(int* begin, int* end, long size);
void final_insertion_sort(int* begin, int* end);

void strange_sort_list(std::vector<int>& vec) {
    std::vector<int> temp(vec.size());
    std::copy(vec.begin(), vec.end(), temp.begin());
    
    int* begin = temp.data();
    int* end = begin + vec.size();

    if (end - begin > 64) {
        introsort_loop(begin, end, end - begin);
    } else {
        final_insertion_sort(begin, end);
    }

    vec = std::move(temp);
}

void introsort_loop(int* begin, int* end, long size) {
    if (size <= 1) return;

    long mid = (size >> 1);
    std::nth_element(begin, begin + mid, end);

    introsort_loop(begin, begin + mid, mid);
    introsort_loop(begin + mid, end, size - mid);
}

void final_insertion_sort(int* begin, int* end) {
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
    assert (issame(strange_sort_list({1, 2, 3, 4}) , {1, 4, 2, 3}));
    assert (issame(strange_sort_list({5, 6, 7, 8, 9}) , {5, 9, 6, 8, 7}));
    assert (issame(strange_sort_list({1, 2, 3, 4, 5}) , {1, 5, 2, 4, 3}));
    assert (issame(strange_sort_list({5, 6, 7, 8, 9, 1}) , {1, 9, 5, 8, 6, 7}));
    assert (issame(strange_sort_list({5, 5, 5, 5}) , {5, 5, 5, 5}));
    assert (issame(strange_sort_list({}) , {}));
    assert (issame(strange_sort_list({1,2,3,4,5,6,7,8}) , {1, 8, 2, 7, 3, 6, 4, 5}));
    assert (issame(strange_sort_list({0,2,2,2,5,5,-5,-5}) , {-5, 5, -5, 5, 0, 2, 2, 2}));
    assert (issame(strange_sort_list({111111}) , {111111}));
}
