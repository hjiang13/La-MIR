#include <string>
#include <algorithm>

std::string anti_shuffle(const std::string& input) {
    std::string result;
    std::string temp = input;
    std::sort(temp.begin(), temp.end());
    result += temp;
    return result;
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
