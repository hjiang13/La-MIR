bool iscuber(int x) {
  int y = abs(x);
  int i = 0;
  while (i <= y) {
    int j = i * i;
    if (j <= y) {
      i++;
    } else {
      break;
    }
  }
  return i <= y;
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
