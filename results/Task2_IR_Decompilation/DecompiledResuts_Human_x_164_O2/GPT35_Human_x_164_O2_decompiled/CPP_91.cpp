```cpp
#include <string>

using namespace std;

int is_bored(basic_string<char>* str) {
  int len = str->size();
  
  if (len == 0) {
    return 0;
  }

  int count = 0;
  int sum = 0;
  int temp = 0;
  int flag = 0;

  for (int i = 0; i < len; i++) {
    char c = (*str)[i];
    
    if (c == ' ') {
      sum += temp;
      temp = 0;
    } else {
      temp++;
    }
  }

  sum += temp;

  return sum;
}
```