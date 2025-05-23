```c
#include <stdbool.h>

bool any_int(float arg0, float arg1, float arg2) {
    float var4 = __builtin_roundf(arg0);
    bool var5 = var4 != arg0;
    float var6 = __builtin_roundf(arg1);
    bool var7 = var6 != arg1;
    bool var8 = var5 ? true : var7;
    float var9 = __builtin_roundf(arg2);
    bool var10 = var9 != arg2;
    bool var11 = var8 ? true : var10;
    
    if (var11) {
        return false;
    } else {
        float var13 = arg0 + arg1;
        bool var14 = var13 == arg2;
        float var15 = arg0 + arg2;
        bool var16 = var15 == arg1;
        bool var17 = var14 || var16;
        float var18 = arg1 + arg2;
        bool var19 = var18 == arg0;
        bool var20 = var17 ? true : var19;
        
        return var20;
    }
}
```