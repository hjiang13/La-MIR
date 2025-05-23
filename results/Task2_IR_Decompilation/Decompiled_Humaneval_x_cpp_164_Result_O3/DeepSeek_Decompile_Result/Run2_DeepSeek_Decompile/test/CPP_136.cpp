#include <vector>
#include <cstring> // for memset

using namespace std;

vector<int> largest_smallest_integers(const vector<int>& input) {
    if (input.empty()) {
        return vector<int>(2); // Return a vector with default-initialized elements (0s)
    }

    int largest = 0;
    int smallest = 0;

    size_t size = input.size();
    size_t half_size = size > 1 ? (size / 2) : 1;

    for (size_t i = 0; i < size; ++i) {
        int current = input[i];
        if (current < 0) {
            if (smallest == 0 || current < smallest) {
                smallest = current;
            }
        } else {
            if (largest == 0 || current > largest) {
                largest = current;
            }
        }
    }

    return vector<int>{largest, smallest};
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
