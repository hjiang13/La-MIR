#include <string>
#include <cstring>

void anti_shuffle(std::string &result, const std::string &input) {
    size_t input_size = input.size();
    if (input_size > 15) {
        result.resize(input_size);
        memcpy(&result[0], input.data(), input_size);
    } else {
        result = input;
    }
    result.push_back('\0');
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
