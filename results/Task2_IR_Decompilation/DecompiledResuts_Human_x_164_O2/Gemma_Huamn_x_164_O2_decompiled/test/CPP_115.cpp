#include <stdint.h>
int32_t _Z8max_fillSt6vectorIS_IiSaIiEESaIS1_EEi(
    void * _0, int32_t _1) {
  int32_t _3 = *(int64_t *)(((char *)_0) + 8);
  int32_t _4 = *(int64_t *)(((char *)_0) + 0);
  int64_t _5 = _3 - _4;
  int32_t _6 = _5 == 0;
  if (_6) {
    return 0;
  }
  int64_t _7 = _5 / 24;
  int64_t _8 = _7 < 1 ? 1 : _7;
  int32_t _9 = 0;
  int32_t _10 = 0;
  for (; _8 > 0; _8--) {
    int32_t _11 = _9;
    int32_t _12 = _10;
    int64_t _13 = *(int64_t *)(((char *)_4) + (_11 * 24));
    int64_t _14 = *(int64_t *)(((char *)_4) + (_11 * 24) + 8);
    int64_t _15 = _13 - _14;
    int32_t _16 = _15 == 0;
    if (_16) {
      _9 = _11 + 1;
      continue;
    }
    int64_t _17 = _15 / 4;
    int64_t _18 = _17 < 1 ? 1 : _17;
    int32_t _19 = 0;
    for (; _18 > 0; _18--) {
      int32_t _20 = _19;
      int32_t _21 = _12;
      int32_t * _22 = (int32_t *)(((char *)_14) + (_20 * 4));
      int32_t * _23 = (int32_t *)(((char *)_14) + (_20 * 4) + 4);
      int32_t _24 = _22[0] + _21;
      int32_t _25 = _23[0] + _24;
      _19 = _20 + 1;
      _12 = _25;
    }
    _9 = _11 + 1;
    _10 = _12;
  }
  return _10;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (max_fill({{0,0,1,0}, {0,1,0,0}, {1,1,1,1}}, 1) == 6);
    assert (max_fill({{0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}}, 2) == 5);
    assert (max_fill({{0,0,0}, {0,0,0}}, 5) == 0);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 2) == 4);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 9) == 2);
}
