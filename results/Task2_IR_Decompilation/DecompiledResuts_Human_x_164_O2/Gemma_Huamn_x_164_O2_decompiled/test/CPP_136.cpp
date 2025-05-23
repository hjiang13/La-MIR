#include <stdlib.h>

void largest_smallest_integers(int* result, int* input, size_t input_size) {
  int smallest = 0;
  int largest = 0;
  for (size_t i = 0; i < input_size; ++i) {
    if (input[i] < 0) {
      if (smallest == 0 || input[i] > smallest) {
        smallest = input[i];
      }
    } else if (input[i] > 0) {
      if (largest == 0 || input[i] < largest) {
        largest = input[i];
      }
    }
  }
  result[0] = smallest;
  result[1] = largest;
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
