Sure, here's the decompiled C++ source code for the provided IR code:

#include <iostream>
#include <vector>

using namespace std;

int sum_squares(vector<float> &v) {
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += ceil(v[i]) * ceil(v[i]);
  }
  return sum;
}

int main() {
  vector<float> v = {1.5, 2.5, 3.5, 4.5};
  cout << sum_squares(v) << endl;
  return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same behavior.