Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <string>

using namespace std;

int hex_key(string str) {
    string key = "2357BD";
    int i = 0;
    while (i < str.length()) {
        if (str[i] == key[0]) {
            i++;
            if (i < str.length() && str[i] == key[1]) {
                i++;
                if (i < str.length() && str[i] == key[2]) {
                    i++;
                    if (i < str.length() && str[i] == key[3]) {
                        i++;
                        if (i < str.length() && str[i] == key[4]) {
                            i++;
                            if (i < str.length() && str[i] == key[5]) {
                                return 5;
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
    return 0;
}

int main() {
    string str = "2357BD";
    cout << hex_key(str) << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or modified during compilation. However, the decompiled code should be functionally equivalent to the original code.