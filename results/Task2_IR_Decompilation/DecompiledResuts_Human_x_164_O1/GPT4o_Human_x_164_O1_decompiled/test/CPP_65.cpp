#include <iostream>
#include <string>
#include <cstdarg>

void circular_shift(std::string& result, int shift, int length) {
    std::string temp;
    const char* format = "%d";
    int written = snprintf(nullptr, 0, format, shift);
    if (written > 0) {
        temp.resize(written);
        snprintf(&temp[0], written + 1, format, shift);
    }

    if (temp.size() > 0 && length > 0) {
        if (temp.size() == 1) {
            result = temp[0];
        } else {
            size_t size = length < temp.size() ? length : temp.size();
            result.append(temp.substr(0, size));
        }
    }
}

int main() {
    std::string result;
    int shift = 1;
    int length = 5;
    circular_shift(result, shift, length);
    std::cout << result << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (circular_shift(100, 2) == "001");
    assert (circular_shift(12, 2) == "12");
    assert (circular_shift(97, 8) == "79");
    assert (circular_shift(12, 1) == "21");
    assert (circular_shift(11, 101) == "11");
}
