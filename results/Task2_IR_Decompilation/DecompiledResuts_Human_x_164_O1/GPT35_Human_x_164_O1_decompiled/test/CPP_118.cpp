```cpp
#include <string>

void get_closest_vowel(std::string& result, const std::string& input) {
    result.clear();
    std::string temp;
    temp = "AEIOUaeiou";

    for (size_t i = 0; i < input.size(); i++) {
        char closest = 0;
        int min_distance = 256;
        for (size_t j = 0; j < temp.size(); j++) {
            int distance = abs(input[i] - temp[j]);
            if (distance < min_distance) {
                min_distance = distance;
                closest = temp[j];
            }
        }
        result += closest;
    }
}

int main() {
    std::string input = "Hello World";
    std::string output;
    get_closest_vowel(output, input);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (get_closest_vowel("yogurt") == "u");
    assert (get_closest_vowel("full") == "u");
    assert (get_closest_vowel("easy") == "");
    assert (get_closest_vowel("eAsy") == "");
    assert (get_closest_vowel("ali") == "");
    assert (get_closest_vowel("bad") == "a");
    assert (get_closest_vowel("most") =="o");
    assert (get_closest_vowel("ab") == "");
    assert (get_closest_vowel("ba") == "");
    assert (get_closest_vowel("quick") == "");
    assert (get_closest_vowel("anime") == "i");
    assert (get_closest_vowel("Asia") == "");
    assert (get_closest_vowel("Above") == "o");
}
