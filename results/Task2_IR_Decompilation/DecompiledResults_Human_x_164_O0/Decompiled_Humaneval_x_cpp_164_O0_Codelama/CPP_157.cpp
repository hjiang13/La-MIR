The provided IR code is for a function that takes three float arguments and returns a boolean value. The function appears to be a right-angle triangle test, where it checks if the sum of the squares of the lengths of the sides is equal to the square of the length of the hypotenuse.

Here is the decompiled C++ code for the function:
```
bool right_angle_triangle(float a, float b, float c) {
  float ab = a * b;
  float bc = b * c;
  float ac = a * c;
  float abc = ab + bc;
  float ac2 = ac * 2;
  float abc2 = abc * 2;
  float diff = abc2 - ac2;
  float diff2 = diff * diff;
  float sum = ab + bc + ac;
  float sum2 = sum * sum;
  float test = diff2 - sum2;
  return test < 1.0e-4;
}
```
The decompiled code is similar to the original C++ code, but with some minor differences in the calculation of the test value. The decompiled code uses a more straightforward approach to calculate the test value, while the original code uses a more complex approach that involves more variables and calculations. However, the overall logic of the two codes is the same.