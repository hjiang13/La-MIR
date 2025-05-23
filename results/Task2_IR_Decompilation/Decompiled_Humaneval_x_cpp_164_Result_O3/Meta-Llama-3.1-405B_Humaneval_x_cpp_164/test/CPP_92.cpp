#include <stdio.h>

int any_int(float a, float b, float c) {
  float d = (float)((int)a);
  float e = (float)((int)b);
  float f = (float)((int)c);
  int g = d != a;
  int h = e != b;
  int i = g || h;
  int j = f != c;
  int k = i || j;
  if (k) {
    return 0;
  } else {
    float l = a + b;
    int m = l == c;
    float n = a + c;
    int o = n == b;
    int p = m || o;
    float q = b + c;
    int r = q == a;
    return p || r;
  }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (any_int(2, 3, 1)==true);
    assert (any_int(2.5, 2, 3)==false);
    assert (any_int(1.5, 5, 3.5)==false);
    assert (any_int(2, 6, 2)==false);
    assert (any_int(4, 2, 2)==true);
    assert (any_int(2.2, 2.2, 2.2)==false);
    assert (any_int(-4, 6, 2)==true);
    assert (any_int(2,1,1)==true);
    assert (any_int(3,4,7)==true);
    assert (any_int(3.01,4,7)==false);
}
