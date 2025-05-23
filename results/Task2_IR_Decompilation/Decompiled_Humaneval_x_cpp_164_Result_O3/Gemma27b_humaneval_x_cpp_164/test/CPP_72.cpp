int will_it_fly(int* arr, int size, int target) {
  int* end = arr + size;
  int* start = arr;
  if (start == end) {
    return 0;
  }
  long long len = end - start;
  long long mid = (len / 2);
  while (1) {
    int left = *(start + mid);
    int right = *(end - mid - 1);
    if (left == right) {
      left += mid;
      if (left == target) {
        return 1;
      }
      mid++;
      if (mid == len) {
        return 0;
      }
    } else {
      return 0;
    }
  }
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (will_it_fly({3, 2, 3}, 9)==true);
    assert (will_it_fly({1, 2}, 5) == false);
    assert (will_it_fly({3}, 5) == true);
    assert (will_it_fly({3, 2, 3}, 1) == false);
    assert (will_it_fly({1, 2, 3}, 6) ==false);
    assert (will_it_fly({5}, 5) == true);
}
