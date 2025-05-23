int starts_one_end(int);

int starts_one_end(int x) {
  if (x < 1) {
    return 0;
  }
  if (x == 1) {
    return 1;
  }
  if (x > 2) {
    int y = x - 2;
    if (y < 8) {
      return y == 2 ? 18 : (y == 4 ? 180000 : (y == 6 ? 18000000 : 180000000));
    }
    int z = y & -8;
    int w = z | 2;
    int v = z - 8;
    int u = v >> 3;
    int t = u + 1;
    int s = t & 7;
    if (v < 56) {
      int q = 18;
      int p = 1;
      int o = 1;
      int n = 1;
      for (int m = 0; m < t; ++m) {
        q *= 100000000;
        p *= 100000000;
        o *= 100000000;
        n *= 100000000;
      }
      return s == 0 ? q * p * o * n : (q * p * o * n) * 10;
    }
    int r = 18;
    int l = 1;
    int k = 1;
    int j = 1;
    for (int i = 0; i < t; ++i) {
      r *= 10;
      l *= 10;
      k *= 10;
      j *= 10;
    }
    return s == 0 ? r * l * k * j : (r * l * k * j) * 10;
  }
  return 18;
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
