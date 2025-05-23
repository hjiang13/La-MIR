#include <stdint.h>

typedef struct {
    int* _M_impl;
} std__Vector_base;

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} std__Vector_base_int_std__allocator_int___Vector_impl;

typedef struct {
    std__Vector_base_int_std__allocator_int___Vector_impl _M_impl;
} std__Vector_base_int_std__allocator_int_;

typedef struct {
    std__Vector_base _M_base;
} std__vector;

int64_t llvm_umax_i64(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

int triples_sum_to_zero(std__vector* _x) {
    int32_t* _2 = _x->_M_base._M_impl._M_finish;
    int32_t* _3 = _x->_M_base._M_impl._M_start;
    int64_t _4 = (int64_t)_2 - (int64_t)_3;
    int64_t _5 = _4 >> 2;
    if (_4 == 0) {
        return 0;
    }
    int64_t _7 = llvm_umax_i64(_5, 1);
    int32_t _8 = 2;
    int64_t _9 = 1;
    int64_t _10 = 0;
    while (1) {
        int64_t _12 = _10 + 1;
        int32_t* _13 = _3 + _10;
        int32_t _14 = *_13;
        if (_5 <= _12) {
            break;
        }
        int64_t _16 = _9 + 1;
        int32_t _17 = _8 + 1;
        if (_5 > _16) {
            int64_t _19 = _16 + 1;
            int32_t _20 = _17 + 1;
            if (_5 <= _19) {
                break;
            }
            int32_t* _22 = _3 + _16;
            int32_t _23 = *_22;
            int32_t* _24 = _3 + _19;
            int32_t _25 = *_24;
            int32_t _26 = _14 + _23;
            int32_t _27 = 0 - _25;
            if (_26 == _27) {
                return 1;
            }
            _9 = _19;
            _8 = _20;
            _10 = _12;
            continue;
        }
        _9 = _16;
        _8 = _17;
        _10 = _12;
    }
    return 0;
}
