#include <stdbool.h>
#include <stdint.h>

struct VectorImplData {
    int32_t* _M_start;
    int32_t* _M_finish;
    int32_t* _M_end_of_storage;
};

struct VectorImpl {
    struct VectorImplData _M_impl;
};

struct VectorBase {
    struct VectorImpl _M_impl;
};

struct Vector {
    struct VectorBase _M_base;
};

bool pairs_sum_to_zero(struct Vector* __hidden this) {
    int32_t* _2 = (int32_t*) (((char*) (&this->_M_base._M_impl._M_impl._M_finish)) + 8);
    int32_t* _3 = this->_M_base._M_impl._M_impl._M_start;
    uint64_t _8 = (uint64_t) _2;
    uint64_t _7 = (uint64_t) _3;
    uint64_t _6 = _8 - _7;
    uint64_t _9 = _6 >> 2;
    bool _10 = _6 == 0;
    if (_10) {
        return false;
    } else {
        uint64_t _12 = _9 > 0 ? _9 : 1;
        uint64_t _17 = 0;
        uint64_t _18 = 1;
        bool _19 = true;
        while (true) {
            uint64_t _20 = _17 + 1;
            bool _21 = _9 > _20;
            if (_21) {
                int32_t* _23 = _3 + _17;
                int32_t _24 = *_23;
                uint64_t _28 = _18;
                int32_t* _29 = _3 + _28;
                int32_t _30 = *_29;
                int32_t _31 = 0 - _30;
                bool _32 = _24 == _31;
                if (_32) {
                    return true;
                } else {
                    _18 = _28 + 1;
                    if (_9 <= _28) {
                        return false;
                    }
                }
            } else {
                return false;
            }
            _17 = _20;
            _19 = _21;
        }
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (pairs_sum_to_zero({1, 3, 5, 0}) == false);
    assert (pairs_sum_to_zero({1, 3, -2, 1}) == false);
    assert (pairs_sum_to_zero({1, 2, 3, 7}) == false);
    assert (pairs_sum_to_zero({2, 4, -5, 3, 5, 7}) == true);
    assert (pairs_sum_to_zero({1}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 30}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 31}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 30}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 31}) == false);
}
