```cpp
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
```