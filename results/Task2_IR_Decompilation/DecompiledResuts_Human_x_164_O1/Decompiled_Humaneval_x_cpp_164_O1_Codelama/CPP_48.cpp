Sure, here's the decompiled C++ source code for the provided IR code:

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    if (is_palindrome(str)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways. However, the decompiled code should be functionally equivalent to the original code.