Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
int add(int a, int b) {
  int c = a + b;
  return c;
}
```

Note that I've removed the unnecessary variables and simply performed the addition operation directly. The generated C code is equivalent to the provided LLVM IR code. Let me know if you have any further requests!
#undef NDEBUG
#include<assert.h>
int main(){
    assert (add(0, 1) == 1);
    assert (add(1, 0) == 1);
    assert (add(2, 3) == 5);
    assert (add(5, 7) == 12);
    assert (add(7, 5) == 12);
    for (int i=0;i<100;i+=1)
    {
        int x=rand()%1000;
        int y=rand()%1000;
        assert (add(x, y) == x + y);
    }
}
