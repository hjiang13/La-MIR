Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
int sum_to_n(int n) {
  int temp = n;
  return (temp * (temp + 1)) / 2;
}
```

Note that I've removed the unnecessary variables and optimized the code to match the original functionality. Let me know if you'd like me to explain any part of the transformation!
#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_to_n(1) == 1);
    assert (sum_to_n(6) == 21);
    assert (sum_to_n(11) == 66);
    assert (sum_to_n(30) == 465);
    assert (sum_to_n(100) == 5050);
}
