```c
#include <stdbool.h>

bool any_int(float arg0, float arg1, float arg2) {
    float var0 = arg0;
    float var1 = arg1;
    float var2 = arg2;
    
    float var3 = roundf(var0);
    if (var3 != var0) {
        return false;
    }
    
    float var4 = roundf(var1);
    if (var4 != var1) {
        return false;
    }
    
    float var5 = roundf(var2);
    if (var5 != var2) {
        return false;
    }
    
    if ((var0 + var1) == var2 || (var0 + var2) == var1 || (var1 + var2) == var0) {
        return true;
    } else {
        return false;
    }
}

float roundf(float arg0) {
    float var0 = arg0;
    float var1 = llvm_round_f32(var0);
    return var1;
}

float llvm_round_f32(float arg0);

int main() {
    float num1 = 1.5;
    float num2 = 2.5;
    float num3 = 4.0;
    
    bool result = any_int(num1, num2, num3);
    
    return 0;
}
```