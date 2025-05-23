int smallest_change(vector<int> &v) {
  int n = v.size();
  int i = 0;
  int j = 0;
  int count = 0;
  int min_count = INT_MAX;
  while (i < n) {
    if (v[i] == 1) {
      count++;
    } else {
      count--;
    }
    if (count < 0) {
      count = 0;
    }
    if (count > min_count) {
      min_count = count;
      j = i + 1;
    }
    i++;
  }
  return min_count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (smallest_change({1,2,3,5,4,7,9,6}) == 4);
    assert (smallest_change({1, 2, 3, 4, 3, 2, 2}) == 1);
    assert (smallest_change({1, 4, 2}) == 1);
    assert (smallest_change({1, 4, 4, 2}) == 1);
    assert (smallest_change({1, 2, 3, 2, 1}) == 0);
    assert (smallest_change({3, 1, 1, 3}) == 0);
    assert (smallest_change({1}) == 0);
    assert (smallest_change({0, 1}) == 1);
}
