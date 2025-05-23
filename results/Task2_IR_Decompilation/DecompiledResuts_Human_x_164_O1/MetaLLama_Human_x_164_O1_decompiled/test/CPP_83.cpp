int starts_one_ends(int x) {
  if (x < 1) return 0;
  if (x == 1) return 1;
  if (x <= 2) return 18;
  int result = 18;
  int i = 2;
  do {
    result *= 10;
    i++;
  } while (i != x);
  return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}
