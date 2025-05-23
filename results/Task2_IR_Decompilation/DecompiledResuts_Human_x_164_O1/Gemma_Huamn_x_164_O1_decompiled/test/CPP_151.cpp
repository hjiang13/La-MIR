#include <vector>

int64_t double_the_difference(const std::vector<float>& vec) {
  float* end = vec.data() + vec.size();
  float* begin = vec.data();
  int64_t size = end - begin;
  if (size == 0) {
    return 0;
  }
  int64_t count = (size / 4) > 1 ? (size / 4) : 1;
  int64_t sum = 0;
  for (int64_t i = 0; i < count; ++i) {
    float val = begin[i];
    float rounded = roundf(val);
    float diff = val - rounded;
    if (diff < 0.0001 && val > 0) {
      int32_t roundedInt = (int32_t)rounded;
      if (roundedInt % 2 == 1) {
        sum += roundedInt * roundedInt;
      }
    }
  }
  return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (double_the_difference({}) == 0);
    assert (double_the_difference({5, 4}) == 25);
    assert (double_the_difference({0.1, 0.2, 0.3}) == 0 );
    assert (double_the_difference({-10, -20, -30}) == 0 );
    assert (double_the_difference({-1, -2, 8}) == 0);
    assert (double_the_difference({0.2, 3, 5}) == 34);
    
    
    long long odd_sum=0;
    vector<float> lst={};

    for (int i=-99;i<100;i+=2)
    {
        lst.push_back(i+0.0);
        if (i>0 and i%2==1) odd_sum+=i*i;
    }
  
    assert (double_the_difference(lst) == odd_sum );
}
