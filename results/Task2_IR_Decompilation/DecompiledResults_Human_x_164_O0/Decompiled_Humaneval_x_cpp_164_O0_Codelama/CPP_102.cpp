The provided IR code is for a function that takes two integers as input and returns an integer. The function appears to be a simple implementation of the choose function, which is a mathematical function that calculates the number of ways to choose k items from a set of n items.

Here is the decompiled C++ code for the provided IR code:
```
int choose_num(int n, int k) {
    if (k < 0 || k > n) {
        return -1;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    int r = n - k;
    if (r < 0 || r > n) {
        return -1;
    }
    if (r == 0 || r == n) {
        return 1;
    }
    int num = 1;
    for (int i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}
```
The decompiled code is a simple implementation of the choose function, which calculates the number of ways to choose k items from a set of n items. The function first checks if the input values are valid, and then uses a loop to calculate the number of ways to choose the items. The loop iterates from 1 to r, and at each iteration, it calculates the number of ways to choose the current item and multiplies it by the number of ways to choose the remaining items. The final result is returned as an integer.