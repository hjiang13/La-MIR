The provided IR code is for a function that takes an integer as input and returns the largest divisor of the input that is less than or equal to the square root of the input.

Here is the decompiled C++ code for the function:
```
int largest_divisor(int n) {
  int divisor = 2;
  while (divisor * divisor <= n) {
    if (n % divisor == 0) {
      return divisor;
    }
    divisor++;
  }
  return 1;
}
```
Explanation:

The function starts by initializing a variable `divisor` to 2. It then enters a loop that continues while `divisor * divisor` is less than or equal to `n`.

Inside the loop, the function checks if `n` is divisible by `divisor`. If it is, the function returns `divisor`.

If `n` is not divisible by `divisor`, the function increments `divisor` by 1 and repeats the loop.

After the loop exits, the function returns 1.

It's worth noting that the function is using the "trial division" algorithm to find the largest divisor of `n`. This algorithm is simple but not very efficient, especially for large values of `n`.