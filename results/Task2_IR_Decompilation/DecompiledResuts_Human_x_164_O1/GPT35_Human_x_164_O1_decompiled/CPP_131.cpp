```cpp
#include <cstdio>
#include <string>

int digits(int num) {
  std::__cxx11::basic_string<char> str;
  char buffer[16];
  snprintf(buffer, sizeof(buffer), "%d", num);
  str = buffer;
  
  int count = 0;
  
  for (int i = 0; i < str.size(); i++) {
    char c = str[i];
    int digit = c - '0';
    if (digit % 2 == 1) {
      count += digit;
    } else {
      count *= digit;
    }
  }
  
  return count;
}

int main() {
  int num = 12345;
  int result = digits(num);
  
  printf("Result: %d\n", result);
  
  return 0;
}
```