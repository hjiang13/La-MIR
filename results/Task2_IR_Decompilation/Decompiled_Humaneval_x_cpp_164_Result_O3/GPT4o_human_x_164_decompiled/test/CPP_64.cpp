#include <string>
#include <cstring>

int vowels_count(const std::string& str) {
    const char* vowels = "aeiouAEIOU";
    int count = 0;
    size_t length = str.length();

    for (size_t i = 0; i < length; ++i) {
        char ch = str[i];
        if (strchr(vowels, ch) != nullptr) {
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
