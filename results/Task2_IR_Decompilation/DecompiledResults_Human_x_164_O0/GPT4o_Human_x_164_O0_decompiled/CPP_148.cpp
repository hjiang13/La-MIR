```cpp
#include <iostream>
#include <vector>
#include <string>

void bf(std::vector<std::string>& vec, const std::string& str1, const std::string& str2) {
    vec.reserve(8);
    vec.push_back(str1);
    vec.push_back(str2);
    vec.push_back("Mercury");
    vec.push_back("Venus");
    vec.push_back("Earth");
    vec.push_back("Mars");
    vec.push_back("Jupiter");
    vec.push_back("Saturn");
}

int main() {
    std::vector<std::string> planets;
    bf(planets, "Earth", "Mars");
    for(const auto& planet : planets) {
        std::cout << planet << std::endl;
    }
    return 0;
}
```