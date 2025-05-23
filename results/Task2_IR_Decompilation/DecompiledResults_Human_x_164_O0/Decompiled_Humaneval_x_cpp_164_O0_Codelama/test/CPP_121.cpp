int solutions(vector<int> &v) {
  int size = v.size();
  int i = 0;
  int j = 0;
  int count = 0;
  while (i < size) {
    if (v[i] == 1) {
      j = i + 1;
      while (j < size && v[j] != 1) {
        j++;
      }
      if (j < size) {
        count++;
        i = j + 1;
      } else {
        i++;
      }
    } else {
      i++;
    }
  }
  return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solutions({5, 8, 7, 1})    == 12);
    assert (solutions({3, 3, 3, 3, 3}) == 9);
    assert (solutions({30, 13, 24, 321}) == 0);
    assert (solutions({5, 9}) == 5);
    assert (solutions({2, 4, 8}) == 0);
    assert (solutions({30, 13, 23, 32}) == 23);
    assert (solutions({3, 13, 2, 9}) == 3);
}
