The provided IR code is for a function that takes a single integer argument and returns a boolean value. The function appears to be a simple implementation of the "is cubic" function, which checks whether a given number is a perfect cube.

Here is the decompiled C++ source code for the function:
```
bool is_cubic(int n) {
    int i = 0;
    while (i * i * i < n) {
        i++;
    }
    return i * i * i == n;
}
```
The function uses a loop to iterate over the numbers from 0 to the square root of the input number, and checks whether the cube of each number is equal to the input number. If a perfect cube is found, the function returns true. Otherwise, it returns false.

Note that the decompiled code is not exactly the same as the original source code, but it should produce the same output for the same input.