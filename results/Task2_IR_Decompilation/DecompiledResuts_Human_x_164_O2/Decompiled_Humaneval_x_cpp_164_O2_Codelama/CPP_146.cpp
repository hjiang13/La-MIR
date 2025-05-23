Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int specialFilter(vector<int> &v) {
    string s;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 10) {
            count++;
            s += to_string(v[i]);
        }
    }
    return count;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int count = specialFilter(v);
    cout << "Count: " << count << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or transformed in various ways during compilation. However, the decompiled code should still accurately represent the original program logic.