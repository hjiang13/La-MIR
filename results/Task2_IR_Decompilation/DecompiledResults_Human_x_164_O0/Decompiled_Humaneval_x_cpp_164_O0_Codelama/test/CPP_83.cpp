int starts_one_end(int input) {
  int result = 0;
  int i = 0;
  while (i < input) {
    result += i;
    i++;
  }
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
