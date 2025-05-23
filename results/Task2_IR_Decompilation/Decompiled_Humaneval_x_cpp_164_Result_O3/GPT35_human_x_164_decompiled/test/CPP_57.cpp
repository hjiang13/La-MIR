#include <vector>

bool monotonic(std::vector<float> &vec) {
  float *data = vec.data();
  float *end = data + vec.size();
  int diff = end - data;
  int numElements = diff >> 2;
  
  if (numElements > 1) {
    float prev = *data;
    int i = 1;
    int j = 0;
    
    while (i < numElements) {
      float current = data[i];
      
      if (current > prev) {
        j = 1;
      } else if (current < prev) {
        j = -1;
      }
      
      prev = current;
      i++;
      
      if (j == 1) {
        return true;
      }
    }
  }
  
  return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (monotonic({1, 2, 4, 10}) == true);
    assert (monotonic({1, 2, 4, 20}) == true);
    assert (monotonic({1, 20, 4, 10}) == false);
    assert (monotonic({4, 1, 0, -10}) == true);
    assert (monotonic({4, 1, 1, 0}) == true);
    assert (monotonic({1, 2, 3, 2, 5, 60}) == false);
    assert (monotonic({1, 2, 3, 4, 5, 60}) == true);
    assert (monotonic({9, 9, 9, 9}) == true);
}
