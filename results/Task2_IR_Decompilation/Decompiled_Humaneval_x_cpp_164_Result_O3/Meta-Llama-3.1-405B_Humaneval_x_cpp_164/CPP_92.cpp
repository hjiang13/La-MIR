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
