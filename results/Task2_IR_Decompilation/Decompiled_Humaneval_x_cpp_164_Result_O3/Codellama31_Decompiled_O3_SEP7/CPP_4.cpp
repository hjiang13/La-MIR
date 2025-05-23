The provided IR code is for a function that takes a vector of floats as input and returns a float. The function appears to be computing the mean absolute deviation of the input vector.

Here is the decompiled C++ code for the provided IR code:
```
float mean_absolute_deviation(vector<float>* input) {
  float sum = 0.0f;
  for (int i = 0; i < input->size(); i++) {
    sum += abs(input->at(i) - input->at(0));
  }
  return sum / input->size();
}
```
Note that the decompiled code is not exactly the same as the original source code, but it should produce the same output for the same input. The differences are likely due to optimizations and other transformations that were applied during the compilation process.