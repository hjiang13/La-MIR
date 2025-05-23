```cpp
#include <vector>
#include <string>

void total_match(std::vector<std::string> &result, std::vector<std::string> &vec1, std::vector<std::string> &vec2) {
    for (size_t i = 0; i < vec1.size(); i++) {
        std::string str = vec1[i];
        result.push_back(str);
    }
    for (size_t i = 0; i < vec2.size(); i++) {
        std::string str = vec2[i];
        result.push_back(str);
    }
}

int main() {
    std::vector<std::string> vec1 = {"Hello", "World"};
    std::vector<std::string> vec2 = {"C++", "Programming"};
    std::vector<std::string> result;

    total_match(result, vec1, vec2);

    return 0;
}
```