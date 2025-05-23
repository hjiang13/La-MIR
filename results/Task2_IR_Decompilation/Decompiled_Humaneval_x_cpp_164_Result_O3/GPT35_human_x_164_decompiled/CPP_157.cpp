```c
#include <stdbool.h>

bool right_angle_triangle(float a, float b, float c) {
    float a_sq = a * a;
    float b_sq = b * b;
    float c_sq = c * c;
    
    float sum_ab = a_sq + b_sq;
    float sum_ac = a_sq + c_sq;
    float sum_bc = b_sq + c_sq;
    
    float diff_ab = sum_ab - c_sq;
    float diff_ac = sum_ac - b_sq;
    float diff_bc = sum_bc - a_sq;
    
    double abs_diff_ab = (diff_ab < 0) ? -diff_ab : diff_ab;
    double abs_diff_ac = (diff_ac < 0) ? -diff_ac : diff_ac;
    double abs_diff_bc = (diff_bc < 0) ? -diff_bc : diff_bc;
    
    if (abs_diff_ab < 1.000000e-04 || abs_diff_ac < 1.000000e-04 || abs_diff_bc < 1.000000e-04) {
        return true;
    } else {
        return false;
    }
}
```