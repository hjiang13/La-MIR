#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> largest_smallest_integers(const std::vector<int>& input) {
    if (input.empty()) {
        return std::vector<int>();
    }

    int largest = 0;
    int smallest = 0;
    bool largest_set = false;
    bool smallest_set = false;

    for (int value : input) {
        if (value < 0) {
            if (!largest_set || value > largest) {
                largest = value;
                largest_set = true;
            }
        } else if (value > 0) {
            if (!smallest_set || value < smallest) {
                smallest = value;
                smallest_set = true;
            }
        }
    }

    std::vector<int> result;
    if (largest_set) {
        result.push_back(largest);
    }
    if (smallest_set) {
        result.push_back(smallest);
    }

    return result;
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
