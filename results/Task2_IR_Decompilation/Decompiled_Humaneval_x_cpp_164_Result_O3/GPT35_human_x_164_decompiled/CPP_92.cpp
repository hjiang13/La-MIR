```cpp
#include <stdbool.h>

bool any_int(float arg0, float arg1, float arg2) {
    float round0 = llvm_round_f32(arg0);
    bool cmp0 = round0 != arg0;
    float round1 = llvm_round_f32(arg1);
    bool cmp1 = round1 != arg1;
    bool cond0 = cmp0 ? true : cmp1;
    float round2 = llvm_round_f32(arg2);
    bool cmp2 = round2 != arg2;
    bool cond1 = cond0 ? true : cmp2;
    if (cond1) {
        return false;
    } else {
        float add0 = arg0 + arg1;
        bool cmp3 = add0 == arg2;
        float add1 = arg0 + arg2;
        bool cmp4 = add1 == arg1;
        bool or_cond = cmp3 || cmp4;
        float add2 = arg1 + arg2;
        bool cmp5 = add2 == arg0;
        bool result = or_cond ? true : cmp5;
        return result;
    }
}
```