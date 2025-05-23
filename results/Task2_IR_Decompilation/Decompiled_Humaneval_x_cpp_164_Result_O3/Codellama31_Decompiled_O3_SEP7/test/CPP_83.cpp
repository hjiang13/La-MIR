#include <cstdint>

int32_t starts_one_end(int32_t input) {
  if (input < 1) {
    return 0;
  }

  if (input == 1) {
    return 1;
  }

  if (input > 2) {
    return 0;
  }

  int32_t result = 1;
  for (int32_t i = 2; i <= input; i++) {
    result *= 10;
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
