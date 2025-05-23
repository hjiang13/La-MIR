```cpp
#include <string>
#include <cctype>

int count_distinct_characters(std::basic_string<char> *str) {
  char *data = &str->_M_dataplus._M_p;
  std::size_t size = str->_M_dataplus._M_string_length;
  
  if (size == 0) {
    return 0;
  }
  
  char *end = data + size;
  char *current = data;
  char *unique_chars = nullptr;
  
  while (current != end) {
    char c = std::tolower(*current);
    *current = c;
    
    bool found = false;
    for (char *p = unique_chars; p != nullptr; ++p) {
      if (*p == c) {
        found = true;
        break;
      }
    }
    
    if (!found) {
      char *temp = new char[size + 1];
      if (unique_chars != nullptr) {
        std::memcpy(temp, unique_chars, size);
        delete[] unique_chars;
      }
      
      unique_chars = temp;
      unique_chars[size] = c;
      size++;
    }
    
    current++;
  }
  
  if (unique_chars != nullptr) {
    delete[] unique_chars;
  }
  
  return size;
}
```