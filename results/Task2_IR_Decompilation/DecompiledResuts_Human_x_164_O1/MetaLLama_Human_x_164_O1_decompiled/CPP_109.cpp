#include <stdint.h>

typedef struct {
    int* _M_impl;
} _Vector_base;

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base_int;

typedef struct {
    _Vector_base _M_base;
} std_vector;

int move_one_ball(std_vector* v) {
    int* _3 = v->_M_base._M_impl._M_finish;
    int* _5 = v->_M_base._M_impl._M_start;
    uintptr_t _6 = (uintptr_t)_3;
    uintptr_t _7 = (uintptr_t)_5;
    uintptr_t _8 = _6 - _7;
    uintptr_t _9 = _8 >> 2;
    int _10 = _8 == 0;
    if (_10) {
        return 1;
    }

    int _12 = _9 > 1;
    if (!_12) {
        int _14 = 0;
        uintptr_t _15 = _9 - 1;
        int* _16 = _5 + _15;
        int _17 = *_16;
        int _18 = *_5;
        int _19 = _17 > _18;
        int _20 = _19;
        int _21 = _14 + _20;
        int _22 = _21 < 2;
        return _22;
    }

    uintptr_t _24 = 1;
    int _25 = 0;
    while (1) {
        uintptr_t _26 = _24;
        int* _27 = _5 + _26;
        int _28 = *_27;
        uintptr_t _29 = _24 - 1;
        int* _30 = _5 + _29;
        int _31 = *_30;
        int _32 = _28 < _31;
        int _33 = _25 + _32;
        uintptr_t _34 = _24 + 1;
        if (_34 == _9) {
            break;
        }
        _25 = _33;
        _24 = _34;
    }

    int _14 = _25;
    uintptr_t _15 = _9 - 1;
    int* _16 = _5 + _15;
    int _17 = *_16;
    int _18 = *_5;
    int _19 = _17 > _18;
    int _20 = _19;
    int _21 = _14 + _20;
    int _22 = _21 < 2;
    return _22;
}
