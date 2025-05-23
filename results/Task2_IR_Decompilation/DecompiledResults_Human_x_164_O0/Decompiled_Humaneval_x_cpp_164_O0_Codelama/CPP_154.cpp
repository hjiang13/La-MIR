Sure, here's the decompiled C++ code for the provided IR:

#include <iostream>
#include <string>

using namespace std;

bool cycpattern_check(string str1, string str2) {
    bool found = false;
    int len1 = str1.length();
    int len2 = str2.length();
    int i = 0;
    int j = 0;

    while (i < len1 && j < len2) {
        if (str1[i] == str2[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == len2) {
        found = true;
    }

    return found;
}

int main() {
    string str1 = "abcdefg";
    string str2 = "cdefg";
    bool result = cycpattern_check(str1, str2);
    if (result) {
        cout << "Cyclic pattern found." << endl;
    } else {
        cout << "Cyclic pattern not found." << endl;
    }
    return 0;
}

Note that the decompiled code may not be identical to the original source code, as the IR code may have been optimized or transformed in various ways. However, the decompiled code should be functionally equivalent to the original code.