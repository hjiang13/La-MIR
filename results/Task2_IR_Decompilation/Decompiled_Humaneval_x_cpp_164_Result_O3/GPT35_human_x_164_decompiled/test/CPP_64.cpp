#include <string>

int vowels_count(std::basic_string<char> *str) {
    std::__cxx11::basic_string<char> vowels = "aeiouAEIOU";

    int count = 0;

    for (char c : *str) {
        if (vowels.find(c) != std::string::npos) {
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
