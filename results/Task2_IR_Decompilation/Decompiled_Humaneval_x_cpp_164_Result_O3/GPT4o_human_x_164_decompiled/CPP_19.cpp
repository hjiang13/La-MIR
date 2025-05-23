```cpp
#include <iostream>
#include <string>
#include <map>
#include <utility>

void sort_numbers(std::string& result, const std::string& input) {
    std::map<std::string, int> numbers {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"four", 4},
        {"five", 5},
        {"nine", 9},
        {"ten", 10}
    };

    // Construct the result based on the input string
    for (const auto& pair : numbers) {
        if (input.find(pair.first) != std::string::npos) {
            result += pair.first + " ";
        }
    }
    result.pop_back(); // Remove the last space
}

int main() {
    std::string result;
    std::string input = "one two three six seven eight four five nine ten";
    sort_numbers(result, input);
    std::cout << result << std::endl;
    return 0;
}
```