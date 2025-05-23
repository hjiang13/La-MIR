```cpp
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> bf(const std::string &str1, const std::string &str2) {
    std::vector<std::string> planets = {
        "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"
    };

    std::vector<std::string> result;
    int index1 = -1, index2 = -1;

    for (size_t i = 0; i < planets.size(); ++i) {
        if (planets[i] == str1) {
            index1 = i;
        }
        if (planets[i] == str2) {
            index2 = i;
        }
    }

    if (index1 == -1 || index2 == -1) {
        return result;
    }

    if (index1 > index2) {
        std::swap(index1, index2);
    }

    for (int i = index1 + 1; i < index2; ++i) {
        result.push_back(planets[i]);
    }

    return result;
}

int main() {
    std::string str1 = "Earth";
    std::string str2 = "Saturn";
    std::vector<std::string> result = bf(str1, str2);

    for (const auto &planet : result) {
        std::cout << planet << std::endl;
    }

    return 0;
}
```