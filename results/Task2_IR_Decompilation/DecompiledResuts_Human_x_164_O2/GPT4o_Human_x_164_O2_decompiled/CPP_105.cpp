```cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>

void by_length(std::vector<int>& result, const std::vector<std::string>& strings) {
    std::map<int, std::string> length_map;
    std::pair<int, std::string> pairs[10];

    pairs[0] = {0, "One"};
    pairs[1] = {1, "Two"};
    pairs[2] = {2, "Three"};
    pairs[3] = {3, "Six"};
    pairs[4] = {4, "Seven"};
    pairs[5] = {5, "Eight"};
    pairs[6] = {6, "Four"};
    pairs[7] = {7, "Five"};
    pairs[8] = {8, "Nine"};
    pairs[9] = {9, "Ten"};

    for (int i = 0; i < 10; ++i) {
        length_map.insert(pairs[i]);
    }

    for (const auto& str : strings) {
        int length = str.length();
        result.push_back(length);
    }
}

int main() {
    std::vector<int> lengths;
    std::vector<std::string> strings = {"One", "Two", "Three", "Six", "Seven", "Eight", "Four", "Five", "Nine", "Ten"};

    by_length(lengths, strings);

    for (const auto& length : lengths) {
        std::cout << length << std::endl;
    }
    return 0;
}
```