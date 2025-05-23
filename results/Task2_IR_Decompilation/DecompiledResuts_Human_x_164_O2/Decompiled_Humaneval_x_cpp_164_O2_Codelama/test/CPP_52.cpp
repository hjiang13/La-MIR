bool below_threshold(vector<int> &v, int threshold) {
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
    if (sum >= threshold) {
      return false;
    }
  }
  return true;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_threshold({1, 2, 4, 10}, 100));
    assert (not(below_threshold({1, 20, 4, 10}, 5)));
    assert (below_threshold({1, 20, 4, 10}, 21));
    assert (below_threshold({1, 20, 4, 10}, 22));
    assert (below_threshold({1, 8, 4, 10}, 11));
    assert (not(below_threshold({1, 8, 4, 10}, 10)));
}
