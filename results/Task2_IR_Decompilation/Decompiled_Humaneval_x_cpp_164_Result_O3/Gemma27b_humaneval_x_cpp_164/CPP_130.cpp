```c
#include <stdlib.h>

void _Z3trii(void* _0, int _1) {
  void* _3 = malloc(8);
  int* _4 = (int*)_3;
  int* _5 = (int*)(_3 + 8);
  *_4 = 1;
  int* _7 = (int*)(_3 + 4);
  *_7 = 3;
  if (_1 == 0) {
    *((void**)_0) = (void*)0;
    *((int**)((char*)_0 + 8)) = (int*)0;
    *((int**)((char*)_0 + 16)) = (int*)0;
    goto _20;
  }
  if (_1 < 2) {
    goto _20;
  }
  int _13 = _1 + 1;
  long long _14 = (long long)_13;
  goto _27;
_15:
  *((void**)_0) = (void*)0;
  void* _17 = malloc(4);
  if (_17 == 0) {
    goto _18;
  }
  *((void**)_0) = _17;
  _17 = 0;
_20:
  int* _21 = _5;
  int* _22 = _5;
  int* _23 = _4;
  *((int**)((char*)_0 + 8)) = _23;
  *((int**)((char*)_0 + 16)) = _22;
  return;
_27:
  long long _28 = _14;
  int* _29 = _4;
  int* _30 = _5;
  int* _31 = _5;
  int _32 = (int)_28;
  int _33 = _32 & 1;
  if (_33 == 0) {
    goto _35;
  }
_37:
  int _36 = _32 >> 1;
  int _37 = _36 + 1;
  if (_30 == _31) {
    goto _41;
  }
_39:
  *_30 = _37;
  _30 = (int*)(_30 + 4);
  goto _130;
_41:
  long long _42 = (long long)(_30 - _29);
  int _43 = (int)(_42 >> 2);



_20:
  int* _21 = _5;
  int* _22 = _5;
  int* _23 = _4;
  *((int**)((char*)_0 + 8)) = _23;
  *((int**)((char*)_0 + 16)) = _22;
  return;
_27:
  long long _28 = _14;
  int* _29 = _4;
  int* _30 = _5;
  int* _31 = _5;
  int _32 = (int)_28;
  int _33 = _32 & 1;
  if (_33 == 0) {
    goto _35;
  }
_37:
  int _36 = _32 >> 1;
  int _37 = _36 + 1;
  if (_30 == _31) {
    goto _41;
  }
_39:
  *_30 = _37;
  _30 = (int*)(_30 + 4);
  goto _130;
_41:
  long long _42 = (long long)(_30 - _29);
  int _43 = (int)(_42 >> 2);
  if (_43 == 0) {
    goto _47;
  }
  int _45 = _43 + 1;
  int _46 = _45 << 2;
  int* _47 = (int*)malloc(_46);
  if (_47 == 0) {
    goto _48;
  }
  int* _49 = _47;
  int _50 = _43;
  int* _51 = _29;

  goto _130;
_47:
  void* _52 = 0;
P
_48:



_20:
  int* _21 = _5;
  int* _22 = _5;
  int* _23 = _4;
  *((int**)((char*)_0 + 8)) = _23;
  *((int**)((char*)_0 + 16)) = _22;
  return;
_27:
  long long _28 = _14;
  int* _29 = _4;
  int* _30 = _5;
  int* _31 = _5;
  int _32 = (int)_28;
  int _33 = _32 & 1;
  if (_33 == 0) {
    goto _35;
  }
_37:
  int _36 = _32 >> 1;
  int _37 = _36 + 1;
  if (_30 == _31) {
    goto _41;
  }
_39:
  *_30 = _37;
  _30 = (int*)(_30 + 4);
  goto _130;
_41:
  long long _42 = (long long)(_30 - _29);
  int _43 = (int)(_42 >> 2);
  if (_43 == 0) {
    goto _47;
  }
  int _45 = _43 + 1;
  int _46 = _45 << 2;
  int* _47 = (int*)malloc(_46);
  if (_47 == 0)