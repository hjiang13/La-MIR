#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

void anti_shuffle(std::string &str1, const std::string &str2) {
    size_t len2 = str2.size();
    if (len2 > 15) {
        str1.reserve(len2);
        std::memcpy(&str1[0], str2.c_str(), len2);
    } else {
        str1.assign(str2);
    }
    str1.push_back('\0');
}

int main() {
    std::string str1;
    std::string str2 = "Hello, World!";
    anti_shuffle(str1, str2);
    std::cout << str1 << std::endl;
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
