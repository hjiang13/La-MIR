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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (move_one_ball({3, 4, 5, 1, 2})==true);
    assert (move_one_ball({3, 5, 10, 1, 2})==true);
    assert (move_one_ball({4, 3, 1, 2})==false);
    assert (move_one_ball({3, 5, 4, 1, 2})==false);
    assert (move_one_ball({})==true);
}
