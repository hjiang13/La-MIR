```c
#include <vector>

void largest_smallest_integers(std::vector<int>& result, const std::vector<int>& input) {
  if (input.empty()) {
    result = {0, 0};
    return;
  }

  int smallest = input[0];
  int largest = input[0];
  for (size_t i = 1; i < input.size(); ++i) {
    if (input[i] < smallest) {
      smallest = input[i];
    }
    if (input[i] > largest) {
      largest = input[i];
    }
  }
  result = {smallest, largest};
}

```