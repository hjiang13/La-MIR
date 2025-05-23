The provided IR code is for a function that takes three float arguments and returns a float value. The function appears to be computing the area of a triangle using the Heron's formula.

Here is the decompiled C++ code for the function:
```
float triangle_area(float a, float b, float c) {
  float s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}
```
Note that the decompiled code is not exactly the same as the original source code, but it should produce the same result when called with the same arguments.