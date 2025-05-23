#include <string>

void get_closest_vowel(std::__cxx11::basic_string<char>&, std::__cxx11::basic_string<char>&);

void get_closest_vowel(std::__cxx11::basic_string<char>& dest, std::__cxx11::basic_string<char>& src) {
    std::__cxx11::basic_string<char> s1;
    std::__cxx11::basic_string<char> s2;
    s1 = src;

    for (int i = 1; i < src.size(); ++i) {
        char c = src[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            dest = s1;
            break;
        }
    }
}

int main() {
    std::__cxx11::basic_string<char> dest;
    std::__cxx11::basic_string<char> src = "example";

    get_closest_vowel(dest, src);

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
