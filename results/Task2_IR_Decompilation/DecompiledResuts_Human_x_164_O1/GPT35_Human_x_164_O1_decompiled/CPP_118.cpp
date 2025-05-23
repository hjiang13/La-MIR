```cpp
#include <string>

void get_closest_vowel(std::string& result, const std::string& input) {
    result.clear();
    std::string temp;
    temp = "AEIOUaeiou";

    for (size_t i = 0; i < input.size(); i++) {
        char closest = 0;
        int min_distance = 256;
        for (size_t j = 0; j < temp.size(); j++) {
            int distance = abs(input[i] - temp[j]);
            if (distance < min_distance) {
                min_distance = distance;
                closest = temp[j];
            }
        }
        result += closest;
    }
}

int main() {
    std::string input = "Hello World";
    std::string output;
    get_closest_vowel(output, input);
    return 0;
}
```