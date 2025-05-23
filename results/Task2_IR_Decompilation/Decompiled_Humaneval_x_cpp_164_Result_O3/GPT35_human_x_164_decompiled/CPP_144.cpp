```cpp
#include <string>
#include <cstdlib>

bool simplify(std::string& str1, std::string& str2) {
    if (str1.size() == 0) {
        return false;
    }

    int pos = 0;
    while (str1[pos] == '/') {
        pos++;
    }

    if (pos == str1.size()) {
        return false;
    }

    str2 = str1.substr(pos);

    return true;
}

int main() {
    std::string input1 = "/basic_string::substr";
    std::string input2;

    if (simplify(input1, input2)) {
        std::cout << "Result: " << input2 << std::endl;
    } else {
        std::cout << "Failed to simplify string" << std::endl;
    }

    return 0;
}
```