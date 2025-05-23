Here is the C source code generated from the provided LLVM IR code:

```c
float triangle_area(float a, float b) {
  float temp_a = a;
  float temp_b = b;
  float result = temp_a * temp_b;
  double result_ext = (double)result;
  result_ext = result_ext * 0.5;
  return (float)result_ext;
}
```

Note that I've kept the variable names as close as possible to the original IR code, but I've also tried to make them more readable and C-like. Let me know if you have any further requests!
#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(triangle_area(5, 3) - 7.5)<1e-4);
    assert (abs(triangle_area(2, 2) - 2.0)<1e-4);
    assert (abs(triangle_area(10, 8) - 40.0)<1e-4);
}
