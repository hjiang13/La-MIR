long long int special_factorial_i(int i) {
  if (i < 1) {
    return 1;
  }
  int j = i + 1;
  long long int k = j - 1;
  long long int l = j - 2;
  long long int m = k & 7;
  if (l < 7) {
    long long int n = 1;
    long long int o = 1;
    long long int p = 1;
    long long int q = 1;
    if (m == 0) {
      return n;
    }
    for (; m != 0; m--) {
      p = p * n;
      o = o * p;
      n = n + 1;
    }
    return o;
  }
  long long int r = k & -8;
  long long int s = 1;
  long long int t = 1;
  long long int u = 1;
  long long int v = 1;
  for (; r != 0; r = r - 8) {
    v = v * s;
    u = u * v;
    s = s + 1;
    v = v * s;
    u = u * v;
    s = s + 1;
    v = v * s;
    u = u * v;
    s = s + 1;
    v = v * s;
    u = u * v;
    s = s + 1;
    v = v * s;
    u = u * v;
    s = s + 1;
    v = v * s;
    u = u * v;
    s = s + 1;
    v = v * s;
    u = u * v;
    s = s + 1;
  }
  return u;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (special_factorial(4) == 288);
    assert (special_factorial(5) == 34560);
    assert (special_factorial(7) == 125411328000);
    assert (special_factorial(1) == 1);
}
