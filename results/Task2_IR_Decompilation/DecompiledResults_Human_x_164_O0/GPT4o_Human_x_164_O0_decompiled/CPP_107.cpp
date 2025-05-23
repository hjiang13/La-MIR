```cpp
#include <iostream>
#include <vector>
#include <string>

void even_odd_palindrome(std::vector<int>& vec, int num) {
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 1; i <= num; ++i) {
        if (i % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    vec.push_back(oddCount);
    vec.push_back(evenCount);
}

int main() {
    std::vector<int> result;
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    even_odd_palindrome(result, number);

    std::cout << "Odd Count: " << result[0] << ", Even Count: " << result[1] << std::endl;

    return 0;
}
```