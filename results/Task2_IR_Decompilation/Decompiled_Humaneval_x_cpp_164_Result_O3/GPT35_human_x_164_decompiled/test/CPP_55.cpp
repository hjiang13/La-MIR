```c
#include <stdio.h>

int f(int x) {
  int arr[1000];
  
  for (int i = 0; i < 1000; i++) {
    arr[i] = 0;
  }
  
  if (x < 2) {
    return arr[x];
  }
  
  arr[2] = 1;
  
  for (int i = 3; i <= x; i++) {
    int sum = arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4];
    arr[i] = sum;
  }
  
  return arr[x];
}

int main() {
  int result = f(10);
  printf("%d\n", result);
  
  return 0;
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
