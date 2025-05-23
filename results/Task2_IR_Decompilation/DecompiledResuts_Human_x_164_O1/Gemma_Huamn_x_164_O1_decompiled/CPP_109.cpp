```c
#include <vector>

bool move_one_ball(std::vector<int>& v) {
  auto end = v.end();
  auto begin = v.begin();
  if(end == begin) {
    return true;
  }
  if(end - begin > 1) {
    int count = 0;

    for(auto it = begin + 1; it != end; ++it) {
      if(*it < *(it - 1)) {
        count++;
      }
    }
    return count < 2;
  } else {
    return begin[0] < end[-1];
  }
}
```