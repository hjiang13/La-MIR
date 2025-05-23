#include <vector>
#include <cmath>

int sum_squares(const std::vector<float>& v) {
  float* end = v.data() + v.size();
  float* begin = v.data();
  
  if (end == begin) {
    return 0;
  }
  
  size_t count = (end - begin) / sizeof(float);
  size_t iters = std::max(count / 4, 1ul);

  int sum = 0;
  for (size_t i = 0; i < iters; ++i) {
    float val = v[i];
    sum += static_cast<int>(std::ceil(val) * std::ceil(val));
  }
  return sum;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_squares({1,2,3})==14);
    assert (sum_squares({1.0,2,3})==14);
    assert (sum_squares({1,3,5,7})==84);
    assert (sum_squares({1.4,4.2,0})==29);
    assert (sum_squares({-2.4,1,1})==6);
    assert (sum_squares({100,1,15,2})==10230);
    assert (sum_squares({10000,10000})==200000000);
    assert (sum_squares({-1.4,4.6,6.3})==75);
    assert (sum_squares({-1.4,17.9,18.9,19.9})==1086);
    assert (sum_squares({0})==0);
    assert (sum_squares({-1})==1);
    assert (sum_squares({-1,1,0})==2);
}
