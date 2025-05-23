```cpp
#include <string>
#include <iostream>

int digits(int num) {
    std::string str = std::to_string(num);
    int count = 0;
    
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if ((c - '0') % 2 == 1) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int num = 123456789;
    int result = digits(num);
    std::cout << "Number of odd digits in " << num << " is: " << result << std::endl;
    
    return 0;
}
```