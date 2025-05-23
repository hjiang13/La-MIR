#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

vector<int> largest_smallest_integers(const vector<int>& input) {
    vector<int> result;
    if (input.empty()) {
        return result;
    }

    size_t size = input.size();
    size_t chunk_size = (size > 4) ? (size / 4) : 1;

    int largest = 0, smallest = 0, zeros = 0;

    for (size_t i = 0; i < size; ++i) {
        int current = input[i];

        if (current < largest) {
            largest = current;
        }

        if (current > smallest) {
            smallest = current;
        }

        if (current == 0) {
            zeros++;
        }
    }

    result.reserve(3);
    result.push_back(largest);
    result.push_back(smallest);
    result.push_back(zeros);

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
