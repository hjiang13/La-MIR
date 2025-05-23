#include <string>
#include <cstring>
#include <new>

void filp_case(std::string& result, const std::string& input) {
    size_t length = input.size();
    if (length == 0) {
        result = "";
        return;
    }
    
    result.resize(length);
    char* res_ptr = &result[0];
    
    for (size_t i = 0; i < length; ++i) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            res_ptr[i] = c - 32;
        } else if (c >= 'A' && c <= 'Z') {
            res_ptr[i] = c + 32;
        } else {
            res_ptr[i] = c;
        }
    }
    
    res_ptr[length] = '\0'; // Null-terminate the string
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
