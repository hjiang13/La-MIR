Here is the decompiled C++ source code for the provided IR code:

```
#include <iostream>
#include <vector>

using namespace std;

bool move_one_ball(vector<int> &balls) {
  int num_balls = balls.size();
  if (num_balls == 0) {
    return false;
  }
  int ball_index = 0;
  while (ball_index < num_balls) {
    if (balls[ball_index] == 1) {
      break;
    }
    ball_index++;
  }
  if (ball_index == num_balls) {
    return false;
  }
  int target_index = ball_index + 1;
  while (target_index < num_balls) {
    if (balls[target_index] == 0) {
      break;
    }
    target_index++;
  }
  if (target_index == num_balls) {
    return false;
  }
  balls[ball_index] = 0;
  balls[target_index] = 1;
  return true;
}
```

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during the compilation process. However, the decompiled code should be functionally equivalent to the original source code, and can be used as a starting point for reverse engineering or debugging purposes.