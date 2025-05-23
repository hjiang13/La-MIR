```c
float triangle_area(float a, float b, float c) {
  if ((a + b > c) && (a + c > b) && (b + c > a)) {
    float s = (a + b + c) / 2.0;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
  }
  return -1.0;
}
```