```cpp
#include <iostream>
#include <map>
#include <string>
#include <tuple>

void histogram(std::map<std::string, int>& m, const std::string& str) {
    using namespace std;
    auto it = m.find(str);
    if (it == m.end()) {
        m[str] = 1;
    } else {
        it->second += 1;
    }
}

int main() {
    std::map<std::string, int> m;
    histogram(m, "example");
    histogram(m, "example");
    
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    return 0;
}
```