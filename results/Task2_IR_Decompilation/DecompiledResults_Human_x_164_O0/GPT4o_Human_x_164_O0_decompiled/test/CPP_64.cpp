#include <string>

int vowels_count(const std::string& str) {
    int count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
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
