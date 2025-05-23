```c
float triangle_area(float a, float b, float c) {
  float d = a + b;
  if (d > c && (a + c) > b && (b + c) > a) {
    float e = d + c;
    float f = 0.5 * e;
    float g = f - a;
    float h = f * g;
    float i = f - b;
    float j = i * h;
    float k = f - c;
    float l = k * j;
    double m = pow((double)l, 0.5);
    return (float)m;
  }
  return -1.0;
}
```