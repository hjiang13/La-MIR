int _Z7iscuberi(int a0) {
  int b2 = abs(a0);
  int b4 = 0;
  while (b4 * b4 * b4 < b2) {
    b4++;
  }
  return b4 * b4 * b4 <= b2;
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
