Here is the decompiled C++ code for the provided IR code:
```
#include <iostream>
#include <vector>

using namespace std;

int count_nums(vector<int> nums) {
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0) {
      count++;
    }
  }
  return count;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  cout << count_nums(nums) << endl;
  return 0;
}
```
Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should still accurately represent the original program logic.