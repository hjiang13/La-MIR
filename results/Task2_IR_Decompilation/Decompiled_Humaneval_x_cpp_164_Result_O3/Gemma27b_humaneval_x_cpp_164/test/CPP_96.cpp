#include <stdlib.h>

typedef struct {
  int* _M_start;
  int* _M_finish;
  int* _M_end_of_storage;
} std_vector_int;

void count_up_to_i(std_vector_int* v, int i) {
  if (i <= 2) {
    return;
  }
  int* v_start = v->_M_start;
  int* v_finish = v->_M_finish;
  int* v_end_of_storage = v->_M_end_of_storage;

  if (v_start == NULL) {
    v_start = (int*)malloc(sizeof(int) * 2);
    v_finish = v_start;
    v_end_of_storage = v_start + 2;
  }

  for (int j = 2; j < i; ++j) {
    if (v_finish == v_end_of_storage) {
      size_t new_size = (v_end_of_storage - v_start) * 2;
      int* new_block = (int*)malloc(sizeof(int) * new_size);
      for (int k = 0; k < (v_finish - v_start); ++k) {
        new_block[k] = v_start[k];
      }
      free(v_start);
      v_start = new_block;
      v_finish = new_block + (v_finish - v_start);
      v_end_of_storage = new_block + new_size;
    }
    *v_finish = j;
    ++v_finish;
  }
  v->_M_start = v_start;
  v->_M_finish = v_finish;
  v->_M_end_of_storage = v_end_of_storage;
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
    assert (issame(count_up_to(5) , {2,3}));
    assert (issame(count_up_to(6) , {2,3,5}));
    assert (issame(count_up_to(7) , {2,3,5}));
    assert (issame(count_up_to(10) , {2,3,5,7}));
    assert (issame(count_up_to(0) , {}));
    assert (issame(count_up_to(22) , {2,3,5,7,11,13,17,19}));
    assert (issame(count_up_to(1) , {}));
    assert (issame(count_up_to(18) , {2,3,5,7,11,13,17}));
    assert (issame(count_up_to(47) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}));
    assert (issame(count_up_to(101) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}));
}
