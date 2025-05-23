#include <vector>

void largest_smallest_integers(std::vector<int>& result, const std::vector<int>& input) {
    int* input_begin = &input[0];
    int* input_end = &input[input.size()];
    
    int largest = 0;
    int smallest = 0;
    
    for (int* it = input_begin; it != input_end; ++it) {
        int value = *it;
        
        if (value < 0) {
            if (smallest == 0 || value > smallest) {
                smallest = value;
            }
        } else {
            if (largest == 0 || value > largest) {
                largest = value;
            }
        }
    }
    
    result.push_back(largest);
    result.push_back(smallest);
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
