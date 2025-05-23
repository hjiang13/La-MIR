#include <stdlib.h>

long long int double_the_difference(float *arr, long long int size) {
  long long int diff = (char *) (arr + size) - (char *) arr;
  if (diff == 0) {
    return 0;
  }
  long long int num_elements = diff / sizeof(float);
  if (num_elements < 1) {
    num_elements = 1;
  }
  long long int sum = 0;
  for (long long int i = 0; i < num_elements; i++) {
    float val = arr[i];
    float rounded_val = roundf(val);
    float diff = val - rounded_val;
    if (diff < 0.0001 && val > 0.0) {
      int rounded_int = (int) rounded_val;
      if (rounded_int % 2 == 1) {
        sum += rounded_int * rounded_int;
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
