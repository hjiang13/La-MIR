#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int count_distinct_characters(std::string str) {
    std::vector<char> distinct_chars;
    for (char c : str) {
        c = std::tolower(c);
        if (std::find(distinct_chars.begin(), distinct_chars.end(), c) == distinct_chars.end()) {
            distinct_chars.push_back(c);
        }
    }
    return distinct_chars.size();
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
