#include <string>

using namespace std;

int vowels_count(const string& s) {
    string vowels = "aeiouAEIOU";
    int count = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    
    // Check the last character again (might be redundant)
    if (s.empty()) return 0;
    if (s[s.size() - 1] == 'u' || s[s.size() - 1] == 'o') {
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
