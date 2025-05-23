Sure, I can decompile the provided IR code into C++ source code.

The IR code you provided is for a function that takes a vector of floats as input and returns the mean absolute deviation of the input vector. The function is implemented using a combination of vectorized instructions and scalar instructions.

Here's the decompiled C++ source code for the function:
```
float mean_absolute_deviation(std::vector<float> &input) {
  float sum = 0.0f;
  for (int i = 0; i < input.size(); i++) {
    sum += std::abs(input[i] - input[0]);
  }
  return sum / input.size();
}
```
Note that the decompiled code is not optimized and may not be the most efficient implementation. The original code may have been optimized using techniques such as loop unrolling, vectorization, or other compiler optimizations.