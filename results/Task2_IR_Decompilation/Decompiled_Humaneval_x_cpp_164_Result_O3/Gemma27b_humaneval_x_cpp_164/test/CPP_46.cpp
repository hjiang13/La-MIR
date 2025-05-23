int fib4(int i) {
  int arr[100] = {0};
  arr[0] = 0;
  arr[1] = 0;
  arr[2] = 2;
  arr[3] = 0;
  if (i < 4) {
    return arr[i];
  }
  int i1 = i + 1;
  arr[4] = 2;
  if (i1 == 5) {
    return arr[i];
  }
  for (int i2 = 6; i2 <= i; i2++) {
    int i3 = i2 - 3;
    int i4 = i2 - 1;
    int i5 = arr[i3] + arr[i4];
    int i6 = i5 + arr[i2 - 2];
    arr[i2] = i6;
  }

  return arr[i];
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib4(5) == 4);
    assert (fib4(8) == 28);
    assert (fib4(10) == 104);
    assert (fib4(12) == 386);
}
