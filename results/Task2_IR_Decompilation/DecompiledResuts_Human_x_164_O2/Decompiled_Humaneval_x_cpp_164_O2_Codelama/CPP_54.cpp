Sure, I can help you with that. The provided IR code appears to be a function that takes two string arguments and returns a boolean value. The function appears to be checking if the two strings have the same characters in the same order.

Here's the decompiled C++ code for the function:
```c
bool same_chars(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
```
The function first checks if the two strings have the same length. If they don't, it immediately returns false. Then, it iterates over each character in the strings and checks if they are the same. If any character is different, it returns false. If the function reaches the end of the loop without finding any differences, it returns true.

Please note that this is just one possible decompilation of the provided IR code, and there may be other valid decompilations depending on the specific implementation and optimization levels used.