Based on the provided LLVM IR code, here is the equivalent C source code:
```
float truncate_number(float x) {
  int i = (int)x;
  float f = (float)i;
  return x - f;
}

#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}