```cpp
#include <string>
#include <stdexcept>
#include <cstdlib>

bool simplify(std::string str1, std::string str2) {
    size_t size1 = str1.size();
    size_t size2 = str2.size();
    
    if (size1 == 0) {
        return false;
    }

    size_t pos1 = 0;
    size_t pos2 = 0;

    while (pos1 < size1 && pos2 < size2) {
        if (str1[pos1] == '/') {
            pos1++;
            continue;
        }
        if (pos2 >= size2 || str1[pos1] != str2[pos2]) {
            return false;
        }
        pos1++;
        pos2++;
    }

    if (pos1 < size1) {
        return false;
    }

    return true;
}

int main() {
    // Example usage
    std::string str1 = "example/path";
    std::string str2 = "example/path";
    bool result = simplify(str1, str2);
    return result ? 0 : 1;
}
```