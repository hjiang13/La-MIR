#include <string>
#include <algorithm>

void anti_shuffle(std::string &result, const std::string &input) {
    result.clear();
    result.resize(input.size());
    std::string temp;

    for (std::size_t i = 0; i < input.size(); ++i) {
        temp.push_back(input[i]);
        if (temp.back() == 32) {
            std::sort(temp.begin(), temp.end());
            std::copy(temp.begin(), temp.end(), result.begin() + i - temp.size() + 1);
            temp.clear();
        }
    }
    if (!temp.empty()) {
        std::sort(temp.begin(), temp.end());
        std::copy(temp.begin(), temp.end(), result.begin() + input.size() - temp.size());
    }
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
