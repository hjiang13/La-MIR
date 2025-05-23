```cpp
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>

void parse_music(std::vector<std::string> &vec, const std::string &input) {
    size_t input_length = input.size();
    if (input_length == 0) {
        return;
    }

    vec.clear();

    for (size_t i = 0; i < input_length; ++i) {
        if (input[i] == 0) {
            break;
        }
        size_t start = i;
        while (i < input_length && input[i] != 0) {
            ++i;
        }
        vec.emplace_back(input.substr(start, i - start));
    }
}

int main() {
    std::vector<std::string> music;
    std::string input = "Song1\0Song2\0Song3\0";
    parse_music(music, input);

    for (const auto &song : music) {
        std::cout << song << std::endl;
    }
    return 0;
}
```