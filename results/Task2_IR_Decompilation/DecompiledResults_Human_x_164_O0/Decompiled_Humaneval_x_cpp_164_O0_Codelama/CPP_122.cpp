The provided IR code is for a function that takes a vector of integers and an integer as input, and returns an integer. The function appears to be adding the elements of the vector that are greater than or equal to -99 and less than or equal to 99 to a running total, and then returning the final total.

Here is the decompiled C++ code for the function:
```
int add_elements(vector<int> &v, int n) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] >= -99 && v[i] <= 99) {
      total += v[i];
    }
  }
  return total;
}
```
Note that the decompiled code is not necessarily the original source code that was used to generate the IR, but it should be functionally equivalent.