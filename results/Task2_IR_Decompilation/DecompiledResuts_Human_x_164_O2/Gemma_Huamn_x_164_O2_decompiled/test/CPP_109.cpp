#include <stdint.h>
int32_t move_one_ball(int32_t* v) {
  int32_t* end = v + *(int32_t*)(v + 8) - *(int32_t*)(v + 4);
  int32_t* ptr = v + *(int32_t*)(v + 4);
  if (end == ptr) {
    return 1;
  }
  int32_t first = *ptr;
  for (int32_t* i = ptr + 1; i < end; i++) {
    if (*i < first) {
      return 0;
    }
    first = *i;
  }
  return 1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (move_one_ball({3, 4, 5, 1, 2})==true);
    assert (move_one_ball({3, 5, 10, 1, 2})==true);
    assert (move_one_ball({4, 3, 1, 2})==false);
    assert (move_one_ball({3, 5, 4, 1, 2})==false);
    assert (move_one_ball({})==true);
}
