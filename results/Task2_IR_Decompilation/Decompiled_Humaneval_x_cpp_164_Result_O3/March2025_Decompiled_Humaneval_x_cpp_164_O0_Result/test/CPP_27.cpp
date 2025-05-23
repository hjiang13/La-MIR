#include <string>
#include <cctype>

std::string filp_case(const std::string& input) {
    std::string result;
    for (char c : input) {
        if (std::islower(c)) {
            result += std::toupper(c);
        } else if (std::isupper(c)) {
            result += std::tolower(c);
        } else {
            result += c;
        }
    }
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
