```cpp
#include <iostream>
#include <map>
#include <string>

std::map<char, int> histogram(const std::string &input) {
    std::map<char, int> frequencyMap;
    int maxFrequency = 0;

    for (char c : input) {
        if (c != ' ') {
            frequencyMap[c]++;
            if (frequencyMap[c] > maxFrequency) {
                maxFrequency = frequencyMap[c];
            }
        }
    }

    std::map<char, int> result;
    for (const auto &pair : frequencyMap) {
        if (pair.second == maxFrequency) {
            result[pair.first] = pair.second;
        }
    }

    return result;
}

int main() {
    std::string input = "example string";
    std::map<char, int> result = histogram(input);

    for (const auto &pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```