Sure, here's the decompiled C++ code for the provided IR code:

#include <iostream>
#include <vector>

using namespace std;

void rescale_to_unit(vector<float> &result, const vector<float> &input) {
    int n = input.size();
    float min = input[0];
    float max = input[0];
    for (int i = 1; i < n; i++) {
        if (input[i] < min) {
            min = input[i];
        }
        if (input[i] > max) {
            max = input[i];
        }
    }
    float range = max - min;
    for (int i = 0; i < n; i++) {
        result[i] = (input[i] - min) / range;
    }
}

int main() {
    vector<float> input = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<float> result(input.size());
    rescale_to_unit(result, input);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

Note that the decompiled code may not be exactly the same as the original source code, but it should produce the same output and have the same behavior.