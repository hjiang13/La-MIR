The provided IR code is a function that takes a vector of floats as input and returns the maximum element in the vector. The function is implemented using a combination of vector instructions and scalar instructions.

Here is the decompiled C++ code for the function:
```
float max_element(vector<float>* vec) {
  float* data = vec->data();
  float* end = data + vec->size();
  float max = -1.0e4;
  for (; data != end; ++data) {
    if (*data > max) {
      max = *data;
    }
  }
  return max;
}
```
The decompiled code is a simple loop that iterates over the elements of the input vector, keeping track of the maximum element seen so far. The function returns the maximum element at the end of the loop.

Note that the decompiled code is not exactly the same as the original source code, but it should be functionally equivalent. The differences are due to the way the IR code is optimized and the way the decompiler translates it back to C++ code.