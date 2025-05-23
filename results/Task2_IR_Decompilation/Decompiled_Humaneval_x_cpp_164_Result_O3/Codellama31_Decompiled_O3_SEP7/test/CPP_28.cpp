#include <iostream>
#include <string>

using namespace std;

void concatenate(string& s, const vector<string>& v) {
    for (const auto& elem : v) {
        s += elem;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (concatenate({}) == "");
     assert (concatenate({"x", "y", "z"}) == "xyz");
    assert (concatenate({"x", "y", "z", "w", "k"}) == "xyzwk");
}
