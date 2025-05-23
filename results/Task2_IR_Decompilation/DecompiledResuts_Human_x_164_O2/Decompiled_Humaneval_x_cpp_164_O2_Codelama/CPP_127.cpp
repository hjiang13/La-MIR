Sure, I can help you with that. The provided IR code is for a function that takes two vectors as input and returns a string indicating whether the intersection of the two vectors is non-empty.

Here's the decompiled C++ code for the function:
```
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intersection(vector<int> v1, vector<int> v2) {
    int len1 = v1.size();
    int len2 = v2.size();
    int i = 0;
    int j = 0;
    string result = "";

    while (i < len1 && j < len2) {
        if (v1[i] == v2[j]) {
            result += to_string(v1[i]);
            i++;
            j++;
        } else if (v1[i] < v2[j]) {
            i++;
        } else {
            j++;
        }
    }

    if (result.empty()) {
        result = "YES";
    }

    return result;
}
```
The function first checks if the intersection of the two vectors is non-empty by iterating through both vectors and checking if they have any common elements. If the intersection is non-empty, the function returns a string indicating that the intersection is non-empty. Otherwise, it returns an empty string.

Note that the decompiled code is not exactly the same as the original C++ code, but it should be functionally equivalent.