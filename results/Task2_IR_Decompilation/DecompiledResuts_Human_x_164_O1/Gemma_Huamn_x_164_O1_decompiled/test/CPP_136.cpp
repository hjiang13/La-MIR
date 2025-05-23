#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_base;

typedef struct {
    _Vector_base _M_impl;
} vector;

void largest_smallest_integers(vector* largest_smallest, const vector* data) {
  int* start = data->_M_impl._M_finish;
  int* finish = data->_M_impl._M_start;
  ptrdiff_t size = start - finish;
  if (size == 0) {
    largest_smallest->_M_impl._M_start = 0;
    largest_smallest->_M_impl._M_finish = 0;
    largest_smallest->_M_impl._M_end_of_storage = 0;
    return;
  }
  size_t count = (size >> 2) > 0 ? (size >> 2) : 1;
  int smallest = 0;
  int largest = 0;
  for (size_t i = 0; i < count; ++i) {
    int value = *(finish + i);
    if (value < 0 || smallest == 0 || value > smallest) {
      smallest = value;
    }
    if (value > 0 || largest == 0 || value < largest) {
      largest = value;
    }
  }
  largest_smallest->_M_impl._M_start = (int*)malloc(8);
  if (largest_smallest->_M_impl._M_start == NULL) {
    return;
  }
  largest_smallest->_M_impl._M_finish = largest_smallest->_M_impl._M_start + 1;
  largest_smallest->_M_impl._M_end_of_storage = largest_smallest->_M_impl._M_start + 2;
  *(largest_smallest->_M_impl._M_start + 0) = smallest;
  *(largest_smallest->_M_impl._M_start + 1) = largest;
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
