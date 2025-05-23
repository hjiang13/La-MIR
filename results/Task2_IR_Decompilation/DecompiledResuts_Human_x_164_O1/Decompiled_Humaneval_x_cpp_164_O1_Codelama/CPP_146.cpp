Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int specialFilter(vector<int> &v) {
    string s;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 10) {
            s += to_string(v[i]);
        }
    }
    return s.size();
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << specialFilter(v) << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same behavior.