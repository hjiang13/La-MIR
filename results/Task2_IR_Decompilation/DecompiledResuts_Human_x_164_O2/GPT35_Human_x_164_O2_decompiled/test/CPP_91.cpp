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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_bored("Hello world") == 0);
    assert (is_bored("Is the sky blue?") == 0);
    assert (is_bored("I love It !") == 1);
    assert (is_bored("bIt") == 0);
    assert (is_bored("I feel good today. I will be productive. will kill It") == 2);
    assert (is_bored("You and I are going for a walk") == 0);
}
