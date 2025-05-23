#include <vector>
#include <cstring>
#include <algorithm>

extern "C" void largest_smallest_integers(std::vector<int>* result, const std::vector<int>* input) {
    if (input->empty()) {
        memset(result, 0, sizeof(std::vector<int>));
        int* data = new int[2];
        result->data = data;
        return;
    }

    int min_val = input->at(0);
    int max_val = input->at(0);

    for (size_t i = 1; i < input->size(); ++i) {
        int val = input->at(i);
        if (val < min_val) {
            min_val = val;
        }
        if (val > max_val) {
            max_val = val;
        }
    }

    int* data = new int[2];
    data[0] = min_val;
    data[1] = max_val;

    result->data = data;
    result->size = 2;
    result->capacity = 2;
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
    assert (issame(largest_smallest_integers({2, 4, 1, 3, 5, 7}) , {0, 1}));
    assert (issame(largest_smallest_integers({2, 4, 1, 3, 5, 7, 0}) , {0, 1}));
    assert (issame(largest_smallest_integers({1, 3, 2, 4, 5, 6, -2}) , {-2, 1}));
    assert (issame(largest_smallest_integers({4, 5, 3, 6, 2, 7, -7}) , {-7, 2}));
    assert (issame(largest_smallest_integers({7, 3, 8, 4, 9, 2, 5, -9}) , {-9, 2}));
    assert (issame(largest_smallest_integers({}) , {0, 0}));
    assert (issame(largest_smallest_integers({0}) , {0, 0}));
    assert (issame(largest_smallest_integers({-1, -3, -5, -6}) , {-1, 0}));
    assert (issame(largest_smallest_integers({-1, -3, -5, -6, 0}) , {-1, 0}));
    assert (issame(largest_smallest_integers({-6, -4, -4, -3, 1}) , {-3, 1}));
    assert (issame(largest_smallest_integers({-6, -4, -4, -3, -100, 1}) , {-3, 1}));

}
