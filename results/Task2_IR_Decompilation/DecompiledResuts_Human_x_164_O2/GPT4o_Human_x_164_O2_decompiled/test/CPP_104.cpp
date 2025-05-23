#include <vector>
#include <stdexcept>
#include <algorithm>

void unique_digits(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    std::vector<int>::const_iterator start = input.begin();
    std::vector<int>::const_iterator end = input.end();

    if (start == end) return;

    auto it = start;
    while (it != end) {
        int value = *it;
        if (value > 0 && value < 10) {
            if (std::find(result.begin(), result.end(), value) == result.end()) {
                result.push_back(value);
            }
        }
        ++it;
    }

    std::sort(result.begin(), result.end());
}

void realloc_insert(std::vector<int>& vec, int* pos, int* val) {
    size_t size = vec.size();
    if (size >= vec.capacity()) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    
    vec.insert(vec.end(), *val);
}

void introsort_loop(int* start, int* end, size_t length) {
    if (length <= 64) {
        std::sort(start, end);
    } else {
        // Implement introsort for larger sizes...
    }
}

void final_insertion_sort(int* start, int* end) {
    std::sort(start, end);
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
    assert (issame(unique_digits({15, 33, 1422, 1}) , {1, 15, 33}));
    assert (issame(unique_digits({152, 323, 1422, 10}) , {}));
    assert (issame(unique_digits({12345, 2033, 111, 151}) , {111, 151}));
    assert (issame(unique_digits({135, 103, 31}) , {31, 135}));
}
