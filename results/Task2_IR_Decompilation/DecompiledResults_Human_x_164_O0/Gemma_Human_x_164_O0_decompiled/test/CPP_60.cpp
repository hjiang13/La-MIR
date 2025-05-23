Based on the provided LLVM IR code, here is the equivalent C source code:

```c
int sum_to_n(int n) {
  int result = n * (n + 1);
  return result / 2;
}
```

Let me know if you have any further requests!
#undef NDEBUG
#include<assert.h>
int main(){
    assert (sum_to_n(1) == 1);
    assert (sum_to_n(6) == 21);
    assert (sum_to_n(11) == 66);
    assert (sum_to_n(30) == 465);
    assert (sum_to_n(100) == 5050);
}
