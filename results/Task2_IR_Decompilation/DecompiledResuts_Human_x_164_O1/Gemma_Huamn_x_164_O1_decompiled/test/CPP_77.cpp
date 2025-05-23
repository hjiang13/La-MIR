int _Z7iscuberi(int);

int _Z7iscuberi(int x) {
  int x1 = abs(x);
  int i = 0;
  while (i*i*i < x1) {
    i = i + 1;
  }
  return i*i*i <= x1;
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
