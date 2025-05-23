int _Z7iscuberi(int a0) {
  int i2 = llvm_abs(a0, 1);
  int i4 = 0;
  while (i4 * i4 * i4 < i2) {
    i4++;
  }
  return i4 * i4 * i4 <= i2;
}

int llvm_abs(int a0, int a1) {
  return a0 < 0 ? -a0 : a0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (iscuber(1) == true);
    assert (iscuber(2) == false);
    assert (iscuber(-1) == true);
    assert (iscuber(64) == true);
    assert (iscuber(180) == false);
    assert (iscuber(1000) == true);
    assert (iscuber(0) == true);
    assert (iscuber(1729) == false);
}
