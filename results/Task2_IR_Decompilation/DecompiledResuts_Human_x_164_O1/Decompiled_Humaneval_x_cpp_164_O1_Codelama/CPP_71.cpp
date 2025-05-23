The provided IR code is for a function that calculates the area of a triangle given the lengths of its three sides. The function takes three float arguments and returns a float value.

Here is the decompiled C++ code for the function:
```
float triangle_area(float side1, float side2, float side3) {
  float semi_perimeter = (side1 + side2 + side3) / 2;
  float area = sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side2) * (semi_perimeter - side3));
  return area;
}
```
Note that the decompiled code is not exactly the same as the original C++ code, but it is functionally equivalent. The decompiler has been able to accurately reconstruct the logic of the original code from the IR representation.