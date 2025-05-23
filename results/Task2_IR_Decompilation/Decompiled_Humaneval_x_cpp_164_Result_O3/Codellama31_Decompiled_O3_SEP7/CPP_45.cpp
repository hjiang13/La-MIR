Here is the decompiled C++ source code for the provided IR code:

#include <iostream>

using namespace std;

float triangle_area(float base, float height) {
  return (base * height) / 2;
}

int main() {
  float base, height;
  cout << "Enter the base and height of the triangle: ";
  cin >> base >> height;
  cout << "The area of the triangle is: " << triangle_area(base, height) << endl;
  return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways. However, the decompiled code should be functionally equivalent to the original code.