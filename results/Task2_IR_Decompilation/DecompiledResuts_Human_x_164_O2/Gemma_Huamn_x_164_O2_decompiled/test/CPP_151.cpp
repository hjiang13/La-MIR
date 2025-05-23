#include <vector>

extern "C" long long double_the_difference(std::vector<float> const& v) {
  auto size = v.size();
  if (size == 0) {
    return 0;
  }
  long long count = 0;
  for (long long i = 0; i < size; ++i) {
    float val = v[i];
    float rounded = roundf(val);
    float diff = val - rounded;
    if (diff < 0.0001f && val > 0.0f) {
      int rounded_int = static_cast<int>(rounded);
      if (rounded_int % 2 == 1) {
        count += rounded_int * rounded_int;
      }
    }
  }
  return count;
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
