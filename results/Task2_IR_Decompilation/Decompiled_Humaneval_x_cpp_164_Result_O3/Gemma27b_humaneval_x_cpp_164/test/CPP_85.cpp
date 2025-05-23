#include <stdio.h>

int add(int *begin, int *end) {
  int sum = 0;
  while (begin != end) {
    sum += *begin;
    ++begin;
  }
  return sum;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int sum = add(arr, arr + 5);
  printf("Sum: %d\n", sum);
  return 0;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (add({4, 88}) == 88);
    assert (add({4, 5, 6, 7, 2, 122}) == 122);
    assert (add({4, 0, 6, 7}) == 0);
    assert (add({4, 4, 6, 8}) == 12);
}
