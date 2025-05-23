The provided IR code is for a function that takes two integers as input and returns an integer. The function appears to be a simple implementation of the choose function, which calculates the number of ways to choose k items from a set of n items.

Here is the decompiled C++ code for the function:
```
int choose_num(int n, int k) {
    if (k < 0 || k > n) {
        return -1;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}
```
The decompiled code is in C++ and uses integer arithmetic to calculate the binomial coefficient. The function takes two integers as input, `n` and `k`, and returns an integer representing the number of ways to choose `k` items from a set of `n` items. If `k` is less than 0 or greater than `n`, the function returns -1. If `k` is 0 or `n`, the function returns 1. Otherwise, the function uses a loop to calculate the binomial coefficient using the formula (n choose k) = (n! / (k! \* (n-k)!)). The result is returned as an integer.