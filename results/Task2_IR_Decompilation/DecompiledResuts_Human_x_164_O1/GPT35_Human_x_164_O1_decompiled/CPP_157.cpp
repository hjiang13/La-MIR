```c
#include <stdbool.h>

float llvm_fabs_f32(float);

bool right_angle_triangle(float a, float b, float c) {
    float a_squared = a * a;
    float b_squared = b * b;
    float c_squared = c * c;
    
    float sum_ab = a_squared + b_squared;
    float diff_c = sum_ab - c_squared;
    double abs_diff_c = (double)llvm_fabs_f32(diff_c);
    
    if (abs_diff_c < 1.000000e-04)
        return true;
    
    float sum_ac = a_squared + c_squared;
    float diff_b = sum_ac - b_squared;
    double abs_diff_b = (double)llvm_fabs_f32(diff_b);
    
    if (abs_diff_b < 1.000000e-04)
        return true;
    
    float sum_bc = b_squared + c_squared;
    float diff_a = sum_bc - a_squared;
    double abs_diff_a = (double)llvm_fabs_f32(diff_a);
    
    if (abs_diff_a < 1.000000e-04)
        return true;
    
    return false;
}
```