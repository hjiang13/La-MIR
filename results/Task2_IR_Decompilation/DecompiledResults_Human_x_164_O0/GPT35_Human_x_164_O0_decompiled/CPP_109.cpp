```c
#include <vector>

bool move_one_ball(std::vector<int> &vec) {
  if (vec.size() == 0) {
    return true;
  } else {
    for (int i = 1; i < vec.size(); i++) {
      if (vec[i] < vec[i - 1]) {
        int temp = vec[i];
        vec[i] = vec[i - 1];
        vec[i - 1] = temp;
      }
    }
    if (vec[vec.size() - 1] > vec[0]) {
      return true;
    } else {
      return false;
    }
  }
}

int main() {
  std::vector<int> vec = {4, 2, 1, 3};
  bool result = move_one_ball(vec);
  return 0;
}
```