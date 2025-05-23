Based on the provided LLVM IR code, here is the equivalent C source code:

```c
float truncate_number(float x) {
    float temp = x;
    int truncated = (int) temp;
    float result = temp - (float) truncated;
    return result;
}
```

Please note that this C code is a direct translation of the provided LLVM IR code and may not be the most efficient or optimal implementation.
#undef NDEBUG
#include<assert.h>
int main(){
 assert (truncate_number(3.5) == 0.5); 
 assert (abs(truncate_number(1.33) - 0.33) < 1e-4);
  assert (abs(truncate_number(123.456) - 0.456) < 1e-4);
}