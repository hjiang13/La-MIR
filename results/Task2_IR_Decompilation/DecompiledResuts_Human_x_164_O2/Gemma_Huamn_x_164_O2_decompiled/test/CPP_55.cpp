int fib(int n) {
  int arr[1000] = {0};
  arr[0] = 0;
  arr[1] = 1;
  if (n < 2) {
    return arr[n];
  }
  n++;
  arr[2] = 1;
  if (n == 3) {
    return arr[n-1];
  }
  for (int i = 3; i < n; i++) {
    arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
  }
  return arr[n-1];
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib(10) == 55);
    assert (fib(1) == 1);
    assert (fib(8) == 21);
    assert (fib(11) == 89);
    assert (fib(12) == 144);
}
