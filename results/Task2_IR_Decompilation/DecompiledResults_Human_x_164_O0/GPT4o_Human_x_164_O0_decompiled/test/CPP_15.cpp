#include <string>
#include <stdexcept>
#include <cstdio>
#include <cstdarg>

std::string to_string(int value) {
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%d", value);
    return std::string(buffer);
}

void string_sequence(std::string& result, int n) {
    std::string temp;
    for (int i = 0; i <= n; ++i) {
        temp = to_string(i);
        result += temp;
        if (i < n) {
            result += " ";
        }
    }
}

int main() {
    std::string result;
    string_sequence(result, 10);
    printf("%s\n", result.c_str());
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_sequence(0) == "0");
    assert (string_sequence(3) == "0 1 2 3");
     assert (string_sequence(10) == "0 1 2 3 4 5 6 7 8 9 10");
}
