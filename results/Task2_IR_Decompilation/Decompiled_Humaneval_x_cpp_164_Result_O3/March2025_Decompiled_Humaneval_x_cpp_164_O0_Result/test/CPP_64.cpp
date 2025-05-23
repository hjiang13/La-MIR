#include <string>

int vowels_count(const std::string& input) {
    const std::string vowels = "aeiouAEIOU";
    int count = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        if (vowels.find(input[i]) != std::string::npos) {
            ++count;
        }
    }
    if (!input.empty() && (input.back() == 'y' || input.back() == 'Y')) {
        ++count;
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
