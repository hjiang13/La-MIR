#include <string>
#include <cstring>

void filp_case(std::string &result, const std::string &input) {
    result = std::string();
    size_t input_length = input.size();
    
    if (input_length == 0) {
        return;
    }

    result.resize(input_length);
    for (size_t i = 0; i < input_length; ++i) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            result[i] = c - 32; // Convert to uppercase
        } else if (c >= 'A' && c <= 'Z') {
            result[i] = c + 32; // Convert to lowercase
        } else {
            result[i] = c; // Leave unchanged
        }
    }
    result[input_length] = '\0'; // Null-terminate the string
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
