```c++
#include <vector>
#include <iostream>

void sort_third(std::vector<int>& result, std::vector<int>& input) {
    int* begin = &input[0];
    int* end = &input[input.size()];

    if (begin == end) {
        return;
    }

    int* current = begin;
    int* next = begin + 1;

    while (next != end) {
        if (*current < *next) {
            int temp = *current;
            *current = *next;
            *next = temp;
        }

        current++;
        next++;
    }

    result = input;
}

int main() {
    std::vector<int> input = {3, 2, 1};
    std::vector<int> result;

    sort_third(result, input);

    for (int num : result) {
        std::cout << num << " ";
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
    assert (issame(sort_third({1, 2, 3}) , sort_third({1, 2, 3})));
    assert (issame(sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}) , sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10})));
    assert (issame(sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}) , sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10})));
    assert (issame(sort_third({5, 6, 3, 4, 8, 9, 2}) , {2, 6, 3, 4, 8, 9, 5}));
    assert (issame(sort_third({5, 8, 3, 4, 6, 9, 2}) , {2, 8, 3, 4, 6, 9, 5}));
    assert (issame(sort_third({5, 6, 9, 4, 8, 3, 2}) , {2, 6, 9, 4, 8, 3, 5}));
    assert (issame(sort_third({5, 6, 3, 4, 8, 9, 2, 1}) , {2, 6, 3, 4, 8, 9, 5, 1}));
}
