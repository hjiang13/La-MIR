```c
#include <string>
#include <cstring>

using namespace std;

int how_many_times(string& s1, string& s2) {
    int count = 0;
    int index = 0;
    
    if (s1.length() == 0) {
        return count;
    } else {
        while (index <= s1.length() - s2.length()) {
            if (s1.substr(index, s2.length()) == s2) {
                count++;
                index++;
            } else {
                index++;
            }
        }
    }
    
    return count;
}

int main() {
    string s1 = "Hello, world! Hello, universe!";
    string s2 = "Hello";
    
    int result = how_many_times(s1, s2);
    
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (how_many_times("", "x") == 0);
    assert (how_many_times("xyxyxyx", "x") == 4);
     assert (how_many_times("cacacacac", "cac") == 4);
    assert (how_many_times("john doe", "john") == 1);
}
