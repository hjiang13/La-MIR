Certainly! Here is the decompiled C++ source code for the provided IR code:

#include <iostream>
#include <vector>

using namespace std;

bool has_close_elements(vector<float> &vec, float eps) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (abs(vec[i] - vec[j]) < eps) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<float> vec = {1.0, 2.0, 3.0, 4.0, 5.0};
    float eps = 0.5;
    cout << has_close_elements(vec, eps) << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, as the IR code may have been optimized or modified during compilation. However, the decompiled code should be functionally equivalent to the original source code.