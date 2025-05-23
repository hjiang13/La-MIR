int count_nums(int* arr, int size) {
  if (size == 0) {
    return 0;
  }
  long long int nElements = size / 4;
  long long int nIterations = (nElements > 1) ? nElements : 1;
  int count = 0;
  for (long long int i = 0; i < nIterations; i++) {
    int num = arr[i];
    if (num > 0) {
      int sum = 0;
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      if (sum > num) {
        count += 1;
      }
    }
  }
  return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_nums({}) == 0);
    assert (count_nums({-1, -2, 0}) == 0);
    assert (count_nums({1, 1, 2, -2, 3, 4, 5}) == 6);
    assert (count_nums({1, 6, 9, -6, 0, 1, 5}) == 5);
    assert (count_nums({1, 100, 98, -7, 1, -1}) == 4);
    assert (count_nums({12, 23, 34, -45, -56, 0}) == 5);
    assert (count_nums({-0, 1}) == 1);
    assert (count_nums({1}) == 1);
}
