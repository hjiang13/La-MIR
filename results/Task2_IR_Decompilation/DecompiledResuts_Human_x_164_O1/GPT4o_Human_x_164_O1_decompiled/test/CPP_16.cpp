#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <memory>

int count_distinct_characters(const std::string& input) {
    size_t length = input.size();
    if (length == 0) {
        return 0;
    }

    // Temporary storage for distinct characters
    std::vector<char> distinctChars;
    for (size_t i = 0; i < length; ++i) {
        char ch = std::tolower(input[i]);
        if (std::find(distinctChars.begin(), distinctChars.end(), ch) == distinctChars.end()) {
            distinctChars.push_back(ch);
        }
    }

    return distinctChars.size();
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
