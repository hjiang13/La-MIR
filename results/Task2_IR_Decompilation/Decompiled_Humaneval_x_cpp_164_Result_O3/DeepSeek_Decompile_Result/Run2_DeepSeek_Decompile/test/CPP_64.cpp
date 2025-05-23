#include <string>

using namespace std;

int vowels_count(const string &s) {
    string vowels = "aeiouAEIOU";
    int count = 0;
    
    if (s.length() == 0) {
        return 0;
    }

    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }

    // Additional check for the last character (seems redundant but following IR)
    if (s.back() == 'u' || s.back() == 'U') {
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
