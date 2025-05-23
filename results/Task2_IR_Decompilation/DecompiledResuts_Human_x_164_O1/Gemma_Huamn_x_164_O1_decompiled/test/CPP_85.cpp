#include <stdint.h>

int _Z3addSt6vectorIiSaIiEE(const struct std_vector* _0) {
  const int32_t* _2 = (const int32_t*)(_0->impl.data._M_finish);
  const int32_t* _4 = (const int32_t*)(_0->impl.data._M_start);
  int64_t _6 = (int64_t)_2;
  int64_t _7 = (int64_t)_4;
  int64_t _8 = _6 - _7;
  int64_t _9 = _8 >> 2;
  if (_9 > 1) {
    int64_t _12 = _9 - 2;
    int64_t _13 = _12 >> 1;
    int32_t _15 = 0;
    for (int64_t _17 = 0; _17 <= _13; ++_17) {
      int64_t _18 = _17 * 2 + 1;
      int32_t _21 = _4[_18];
      int32_t _22 = _21 & 1;
      int32_t _24 = (_22 == 0) ? _21 : 0;
      _15 += _24;
    }
    return _15;
  }
  return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add({4, 88}) == 88);
    assert (add({4, 5, 6, 7, 2, 122}) == 122);
    assert (add({4, 0, 6, 7}) == 0);
    assert (add({4, 4, 6, 8}) == 12);
}
