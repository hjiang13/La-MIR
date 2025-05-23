```c
#include <iostream>
#include <string>
#include <algorithm>

int hex_key(std::string key) {
    int count = 0;

    for (int i = 0; i < key.length(); i++) {
        char current = key[i];
        if (current == '2' || current == '3' || current == '5' || current == '7' || current == 'B' || current == 'D') {
            count++;
        }
    }

    return count;
}

int main() {
    std::string key = "2357BD";
    int result = hex_key(key);
    std::cout << "Number of valid characters in key: " << result << std::endl;
    return 0;
}
```