int prod_signs(std::vector<int> const& v) {
  int* end = v.data() + v.size();
  int* begin = v.data();
  if (begin == end) {
    return -32768;
  }
  int n = (end - begin) / 2;
  int64_t n_iter = std::max(n, 1LL);
  int sign = 1;
  int sum = 0;
  for (int64_t i = 0; i < n_iter; ++i) {
    int v1 = begin[i * 2];
    int v2 = begin[i * 2 + 1];
    sum += abs(v1) + abs(v2);
    sign = (v1 == 0 ? 0 : (v1 < 0 ? -sign : sign)) * (v2 == 0 ? 0 : (v2 < 0 ? -sign : sign));
  }
  if (n_iter * 2 < end - begin) {
    int v = begin[n_iter * 2];
    sign = (v == 0 ? 0 : (v < 0 ? -sign : sign));
    sum += abs(v);
  }
  return sign * sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (prod_signs({1, 2, 2, -4}) == -9);
    assert (prod_signs({0, 1}) == 0);
    assert (prod_signs({1, 1, 1, 2, 3, -1, 1}) == -10);
    assert (prod_signs({}) == -32768);
    assert (prod_signs({2, 4,1, 2, -1, -1, 9}) == 20);
    assert (prod_signs({-1, 1, -1, 1}) == 4);
    assert (prod_signs({-1, 1, 1, 1}) == -4);
    assert (prod_signs({-1, 1, 1, 0}) == 0);
}
