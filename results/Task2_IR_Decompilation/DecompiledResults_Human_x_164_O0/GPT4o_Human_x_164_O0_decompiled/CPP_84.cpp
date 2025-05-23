```cpp
#include <iostream>
#include <string>
#include <vector>

void solve(std::string& result, int input) {
    std::string temp;
    bool exceptionOccurred = false;
    try {
        temp = std::to_string(input);
    } catch (...) {
        exceptionOccurred = true;
    }

    if (!exceptionOccurred) {
        int length = temp.length();
        for (int i = 0; i < length; ++i) {
            char c = temp[i];
            if (c >= '0' && c <= '9') {
                result.push_back(c);
            }
        }
    } else {
        result = "basic_string::_M_construct null not valid";
    }

    // Further processing
    if (result.length() > 0) {
        int num = std::stoi(result);
        if (num > 0) {
            num = num % 2;
            temp = std::to_string(num);
            result += temp;
        }
    }
}

int main() {
    std::string result;
    int input = 123; // Example input
    solve(result, input);
    std::cout << result << std::endl;
    return 0;
}
```