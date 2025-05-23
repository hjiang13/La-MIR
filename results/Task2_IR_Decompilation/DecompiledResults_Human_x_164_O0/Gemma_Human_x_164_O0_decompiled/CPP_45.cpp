Here is the C source code generated from the provided LLVM IR code:

```c
float triangle_area(float x, float y) {
  float tmp1 = x;
  float tmp2 = y;
  float tmp3 = tmp1 * tmp2;
  double tmp4 = (double)tmp3;
  double tmp5 = tmp4 * 0.5;
  float tmp6 = (float)tmp5;
  return tmp6;
}
```

Note that I've kept the variable names as `tmpX` to match the IR code's temporary values. If you'd like, I can rename them to something more meaningful, but that would require some interpretation of the code's intent. Let me know!