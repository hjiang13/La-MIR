#include <stdint.h>
int can_arrange(int* arr, int size) {
  if (size == 0) {
    return -1;
  }
  int64_t size_in_bytes = size * sizeof(int);
  int64_t last_element_ptr = (int64_t)arr + size_in_bytes - sizeof(int);
  int64_t i = 0;
  int max_index = -1;
  while (i < size_in_bytes) {
    int current_element = arr[i / sizeof(int)];
    if (i < current_element * sizeof(int)) {
      max_index = i / sizeof(int);
    }
    i += sizeof(int);
  }
  return max_index;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (can_arrange({1,2,4,3,5})==3);
    assert (can_arrange({1,2,4,5})==-1);
    assert (can_arrange({1,4,2,5,6,7,8,9,10})==2);
    assert (can_arrange({4,8,5,7,3})==4);
    assert (can_arrange({})==-1);
}
