```c
#include <vector>
#include <stdexcept>

void count_up_to(std::vector<int>& vec, int num) {
  if (num > 2) {
    int* ptr = nullptr;
    int* last = nullptr;
    int* end = nullptr;
    
    for (int i = 2; i <= num; i++) {
      vec.push_back(i);
    }
  }
}

int main() {
  std::vector<int> vec;
  count_up_to(vec, 10);
  
  return 0;
}
```