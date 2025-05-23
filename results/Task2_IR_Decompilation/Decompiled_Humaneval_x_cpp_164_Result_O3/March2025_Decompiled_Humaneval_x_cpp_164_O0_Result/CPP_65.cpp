```cpp
#include <string>
#include <stdexcept>
#include <sstream>
#include <iterator>
#include <algorithm>

std::string to_string(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string circular_shift(const std::string& input, int shift) {
    if (shift < 0 || shift >= input.length()) {
        throw std::logic_error("basic_string::_M_construct null not valid");
    }
    std::string result;
    std::reverse_iterator<std::string::const_iterator> rbegin(input.begin() + shift);
    std::reverse_iterator<std::string::const_iterator> rend(input.begin());
    result.assign(rbegin, rend);
    return result;
}

int main() {
    std::string str = "example";
    int shift = 3;
    std::string result = circular_shift(str, shift);
    return 0;
}
```