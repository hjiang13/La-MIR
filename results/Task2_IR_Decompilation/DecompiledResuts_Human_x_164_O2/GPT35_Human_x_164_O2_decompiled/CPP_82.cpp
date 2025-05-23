```cpp
#include <string>

bool prime_length(std::basic_string<char> *s) {
  int len = s->size();
  
  if (len < 2) {
    return false;
  }
  
  if (len < 4) {
    return true;
  }
  
  int divisor = 2;
  while (divisor * divisor <= len) {
    if (len % divisor == 0) {
      return false;
    }
    divisor++;
  }
  
  return true;
}
```