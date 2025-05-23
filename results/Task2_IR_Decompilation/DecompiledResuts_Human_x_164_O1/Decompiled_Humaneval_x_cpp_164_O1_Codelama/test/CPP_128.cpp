#include <iostream>
#include <vector>

using namespace std;

int prod_signs(vector<int> &v) {
  int result = 1;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < 0) {
      result *= -1;
    }
  }
  return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (prod_signs({1, 2, 2, -4}) == -9);
    assert (prod_signs({0, 1}) == 0);
    assert (prod_signs({1, 1, 1, 2, 3, -1, 1}) == -10);
    assert (prod_signs({}) == -32768);
    assert (prod_signs({2, 4,1, 2, -1, -1, 9}) == 20);
    assert (prod_signs({-1, 1, -1, 1}) == 4);
    assert (prod_signs({-1, 1, 1, 1}) == -4);
    assert (prod_signs({-1, 1, 1, 0}) == 0);
}
