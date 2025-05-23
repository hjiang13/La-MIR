Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <string>

using namespace std;

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

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    if (same_chars(str1, str2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

Note that the decompiled code may not be identical to the original source code, but it should produce the same output for the same input.