#include <vector>
#include <string>

using namespace std;

string longest(vector<string> const& v) {
    string result;
    result = "";

    for (const string& s : v) {
        if (s.length() > result.length()) {
            result = s;
        }
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
