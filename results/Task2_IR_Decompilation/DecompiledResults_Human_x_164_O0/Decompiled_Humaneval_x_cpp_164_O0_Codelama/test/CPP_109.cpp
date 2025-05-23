bool move_one_ball(vector<int> &balls) {
  int left = 0;
  int right = 0;
  int size = balls.size();
  if (size == 0) {
    return false;
  }
  while (left < size && right < size) {
    if (balls[left] == 1) {
      left++;
    } else {
      right++;
    }
  }
  if (left == size || right == size) {
    return true;
  }
  return false;
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
