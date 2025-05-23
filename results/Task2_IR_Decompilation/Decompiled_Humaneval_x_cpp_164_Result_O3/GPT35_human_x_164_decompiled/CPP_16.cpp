```cpp
#include <string>
#include <algorithm>

int count_distinct_characters(std::string* str) {
  char* data = &(*str)._M_dataplus._M_p;
  std::size_t size = (*str)._M_dataplus._M_string_length;
  
  if (size == 0) {
    return 0;
  }
  
  for (std::size_t i = 0; i < size; ++i) {
    char c = data[i];
    data[i] = std::tolower(static_cast<unsigned char>(c));
  }
  
  std::sort(data, data + size);
  
  std::size_t unique_count = std::unique(data, data + size) - data;
  
  return static_cast<int>(unique_count);
}

int tolower(int c);

void __ZdlPv(void* ptr);

void __ZSt20__throw_length_error(const char* msg) {
  throw std::length_error(msg);
}

void* __Znwm(std::size_t size) {
  return ::operator new(size);
}

void llvm_memmove(void* dest, const void* src, std::size_t size) {
  std::memmove(dest, src, size);
}
```