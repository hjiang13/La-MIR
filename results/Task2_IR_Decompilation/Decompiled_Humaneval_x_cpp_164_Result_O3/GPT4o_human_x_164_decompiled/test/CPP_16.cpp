#include <string>
#include <cctype>
#include <stdexcept>

int count_distinct_characters(const std::string& str) {
    if (str.empty()) return 0;

    size_t length = str.length();
    if (length == 0) return 0;

    std::string lower_str = str;
    for (size_t i = 0; i < length; ++i) {
        lower_str[i] = std::tolower(lower_str[i]);
    }

    size_t distinct_count = 0;
    bool seen[256] = {false};

    for (size_t i = 0; i < length; ++i) {
        if (!seen[lower_str[i]]) {
            seen[lower_str[i]] = true;
            distinct_count++;
        }
    }

    return distinct_count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_distinct_characters("") == 0);
    assert (count_distinct_characters("abcde") == 5);
    assert (count_distinct_characters("abcdecadeCADE") == 5);
    assert (count_distinct_characters("aaaaAAAAaaaa") == 1);
    assert (count_distinct_characters("Jerry jERRY JeRRRY") == 5);
}
