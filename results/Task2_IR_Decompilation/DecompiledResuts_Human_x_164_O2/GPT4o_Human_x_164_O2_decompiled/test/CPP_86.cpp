#include <string>
#include <cstring>
#include <algorithm>

void anti_shuffle(std::string &str1, const std::string &str2) {
    size_t str2_size = str2.size();
    
    if (str2_size > 15) {
        str1.resize(str2_size);
        std::memcpy(&str1[0], str2.data(), str2_size);
    } else {
        for (size_t i = 0; i < str2_size; ++i) {
            str1[i] = str2[i];
        }
    }
    str1[str2_size] = '\0';
}

void insertion_sort(std::string &str) {
    size_t n = str.size();
    for (size_t i = 1; i < n; ++i) {
        char key = str[i];
        size_t j = i - 1;
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            if (j == 0) break; // Prevents unsigned underflow
            --j;
        }
        str[j + 1] = key;
    }
}

void introsort(std::string &str) {
    size_t n = str.size();
    if (n > 16) {
        std::sort(str.begin(), str.end());
    } else {
        insertion_sort(str);
    }
}

int main() {
    std::string str1 = "example";
    std::string str2 = "shuffle";
    
    anti_shuffle(str1, str2);
    introsort(str1);
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (anti_shuffle("Hi") == "Hi");
    assert (anti_shuffle("hello") == "ehllo");
    assert (anti_shuffle("number") == "bemnru");
    assert (anti_shuffle("abcd") == "abcd");
    assert (anti_shuffle("Hello World!!!") == "Hello !!!Wdlor");
    assert (anti_shuffle("") == "");
    assert (anti_shuffle("Hi. My name is Mister Robot. How are you?") == ".Hi My aemn is Meirst .Rboot How aer ?ouy");
}
