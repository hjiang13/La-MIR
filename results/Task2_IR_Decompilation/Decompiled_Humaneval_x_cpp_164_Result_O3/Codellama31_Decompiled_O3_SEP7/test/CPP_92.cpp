#include <iostream>
#include <string>

using namespace std;

bool any_int(float a, float b, float c) {
  float round_a = round(a);
  float round_b = round(b);
  float round_c = round(c);

  if (round_a != a || round_b != b || round_c != c) {
    return true;
  }

  float sum = a + b;
  if (sum == c) {
    return true;
  }

  float diff = a - b;
  if (diff == c) {
    return true;
  }

  float product = a * b;
  if (product == c) {
    return true;
  }

  float quotient = a / b;
  if (quotient == c) {
    return true;
  }

  return false;
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
