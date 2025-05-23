#include <stdlib.h>

typedef struct {
  float* _M_start;
  float* _M_finish;
  float* _M_end_of_storage;
} std__vector;

void _ZNSt6vectorIfSaIfEE13_M_assign_auxIPKfEEvT_S5_St20forward_iterator_tag(std__vector* this, float* first, float* last) {
  long long _M_capacity = (long long)(this->_M_end_of_storage - this->_M_start);
  long long _M_size = (long long)(this->_M_finish - this->_M_start);
  long long _N = (long long)(last - first);
  if (_N > _M_capacity) {
    if (_N > 2305843009213693951LL) {
      abort();
    }
    float* __new_start = (float*)malloc(_N * sizeof(float));
    for (long long i = 0; i < _N; ++i) {
      __new_start[i] = first[i];
    }
    free(this->_M_start);
    this->_M_start = __new_start;
    this->_M_finish = __new_start + _N;
    this->_M_end_of_storage = __new_start + _N;
  } else {
    if (_M_size > _N) {
      for (long long i = 0; i < _N; ++i) {
        this->_M_start[i] = first[i];
      }
      this->_M_finish = this->_M_start + _N;
    } else {
      long long _M_src_size = (long long)(last - first);
      for (long long i = 0; i < _M_size; ++i) {
        this->_M_start[i] = first[i];
      }
      for (long long i = _M_size; i < _M_src_size; ++i) {
        this->_M_start[i] = first[i];
      }
      this->_M_finish = this->_M_start + _M_src_size;
    }
  }
}

void find_closest_elements(std__vector* result, const std__vector* input) {
  float*
#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(find_closest_elements({1.0, 2.0, 3.9, 4.0, 5.0, 2.2}) , {3.9, 4.0}));
    assert (issame(find_closest_elements({1.0, 2.0, 5.9, 4.0, 5.0}) , {5.0, 5.9} ));
    assert (issame(find_closest_elements({1.0, 2.0, 3.0, 4.0, 5.0, 2.2}) ,{2.0, 2.2}));
     assert (issame(find_closest_elements({1.0, 2.0, 3.0, 4.0, 5.0, 2.0}) ,{2.0, 2.0}));
      assert (issame(find_closest_elements({1.1, 2.2, 3.1, 4.1, 5.1}) , {2.2, 3.1}));
}
