int can_arrange(int* arr, int n) {
  if (n == 0) {
    return -1;
  }
  long long size = (long long)n * sizeof(int);
  long long end = (long long)(arr + n);
  long long i;
  for (i = 0; i < end - 1 - (size % 4); i += 4) {
    if (i >= *(arr + i)) {
      return i;
    }
    if (i + 1 >= *(arr + i + 1)) {
      return i + 1;
    }
    if (i + 2 >= *(arr + i + 2)) {
      return i + 2;
    }
    if (i + 3 >= *(arr + i + 3)) {
      return i + 3;
    }
  }
  for (; i < end; i++) {
    if (i >= *(arr + i)) {
      return i;
    }
  }
  return -1;
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
