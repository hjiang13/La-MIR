int fib(int n) {
  int arr[100] = {0};
  arr[0] = 0;
  arr[1] = 0;
  arr[2] = 1;
  if (n < 3) {
    return arr[n];
  }
  int i = n + 1;
  int j = 4;
  arr[3] = 1;
  if (n == 4) {
    return arr[n];
  }
  for (i = 4; i < n; i += 1) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[n];
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fibfib(2) == 1);
    assert (fibfib(1) == 0);
    assert (fibfib(5) == 4);
    assert (fibfib(8) == 24);
    assert (fibfib(10) == 81);
    assert (fibfib(12) == 274);
    assert (fibfib(14) == 927);
}
