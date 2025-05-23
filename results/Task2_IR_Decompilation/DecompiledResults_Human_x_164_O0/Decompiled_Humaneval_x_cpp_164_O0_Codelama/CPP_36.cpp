The provided IR code is for a function that takes an integer as input and returns an integer. The function appears to be a simple implementation of the Fizz Buzz algorithm, which is a common programming exercise that is used to test basic programming skills.

Here is the decompiled C++ source code for the function:
```
int fizz_buzz(int n) {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      result += 1;
    }
  }
  return result;
}
```
The function takes an integer `n` as input and returns an integer. The function loops through the numbers from 1 to `n` and checks if each number is divisible by both 3 and 5. If a number is divisible by both 3 and 5, the function adds 1 to the result. The function returns the result, which is the number of numbers between 1 and `n` that are divisible by both 3 and 5.

It's worth noting that the decompiled code is not the most optimized version of the Fizz Buzz algorithm, but it should give you a good idea of how the algorithm works.