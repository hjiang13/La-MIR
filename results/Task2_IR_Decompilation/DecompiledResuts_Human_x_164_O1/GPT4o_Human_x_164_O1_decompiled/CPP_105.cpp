```cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>

void by_length(std::vector<int>& result, const std::vector<std::string>& strings) {
    std::map<int, std::string> length_map;
    std::pair<int, std::string> pairs[] = {
        {0, "One"},
        {1, "Two"},
        {2, "Three"},
        {3, "Six"},
        {4, "Seven"},
        {5, "Eight"},
        {6, "Nine"},
        {7, "Ten"},
        {8, "Eleven"},
        {9, "Twelve"}
    };

    for (const auto& p : pairs) {
        length_map.insert(p);
    }

    for (const auto& str : strings) {
        int length = str.size();
        if (length_map.find(length) != length_map.end()) {
            result.push_back(length);
        }
    }
}

int main() {
    std::vector<int> lengths;
    std::vector<std::string> strings = {"One", "Two", "Three", "Four", "Five"};
    
    by_length(lengths, strings);
    
    for (const auto& length : lengths) {
        std::cout << length << std::endl;
    }

    return 0;
}
```