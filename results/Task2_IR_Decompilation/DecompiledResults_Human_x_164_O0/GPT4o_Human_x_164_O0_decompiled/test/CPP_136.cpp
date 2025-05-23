#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>

void largest_smallest_integers(std::vector<int>& result, const std::vector<int>& vec) {
    int smallest = 0;
    int largest = 0;
    size_t size = vec.size();

    for (size_t i = 0; i < size; ++i) {
        int value = vec[i];
        if (i == 0 || value < smallest) {
            smallest = value;
        }
        if (i == 0 || value > largest) {
            largest = value;
        }
    }

    result.push_back(smallest);
    result.push_back(largest);
}

int main() {
    std::vector<int> input = {5, 3, 8, 1, 4};
    std::vector<int> output;

    largest_smallest_integers(output, input);

    std::cout << "Smallest: " << output[0] << ", Largest: " << output[1] << std::endl;

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
