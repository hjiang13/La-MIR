```c
#include "stdc++.h"

bool is_nested(const std::string& s) {
  if (s.size() == 0) {
    return false;
  }
  char firstChar = s[0];
  int openBrackets = (firstChar == '[' ? 1 : 0) + (firstChar == '{' ? 1 : 0) + (firstChar == '(' ? 1 : 0);
  int closeBrackets = (firstChar == ']' ? 1 : 0) + (firstChar == '}' ? 1 : 0) + (firstChar == ')' ? 1 : 0);
  int maxBrackets = std::max(openBrackets, closeBrackets);
  for (size_t i = 1; i < s.size(); ++i) {
    char currentChar = s[i];
    openBrackets += (currentChar == '[' ? 1 : 0) + (currentChar == '{' ? 1 : 0) + (currentChar == '(' ? 1 : 0);
    closeBrackets += (currentChar == ']' ? 1 : 0) + (currentChar == '}' ? 1 : 0) + (currentChar == ')' ? 1 : 0);
    maxBrackets = std::max(maxBrackets, std::max(openBrackets, closeBrackets));
  }
  return maxBrackets > 0;
}
```