#include <string>
#include <cstdarg>
#include <stdexcept>

void string_sequence(std::string &result, int count) {
    if (count < 1) {
        return;
    }

    result.reserve(count + 1);
    result.append("0");

    for (int i = 1; i < count; ++i) {
        result += std::to_string(i);
    }
    
    result += '\0';

    if (result.size() > 4611686018427387903) {
        throw std::length_error("basic_string::append");
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_sequence(0) == "0");
    assert (string_sequence(3) == "0 1 2 3");
     assert (string_sequence(10) == "0 1 2 3 4 5 6 7 8 9 10");
}
