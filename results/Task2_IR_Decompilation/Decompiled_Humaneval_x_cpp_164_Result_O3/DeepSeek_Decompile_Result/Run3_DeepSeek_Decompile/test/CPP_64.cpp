#include <string>

using namespace std;

int vowels_count(const string &s) {
    string vowels = "aeiouAEIOU";
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (vowels.find(s[i]) != string::npos) {
            count++;
        }
    }
    // Additional check for the last character (as seen in IR)
    if (!s.empty() && vowels.find(s.back()) != string::npos) {
        count++;
    }
    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (vowels_count("abcde") == 2);
    assert (vowels_count("Alone") == 3);
    assert (vowels_count("key") == 2);
    assert (vowels_count("bye") == 1);
    assert (vowels_count("keY") == 2);
    assert (vowels_count("bYe") == 1);
    assert (vowels_count("ACEDY") == 3);
   
}
