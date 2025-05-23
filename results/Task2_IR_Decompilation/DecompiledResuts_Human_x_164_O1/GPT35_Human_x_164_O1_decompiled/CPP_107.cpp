```cpp
#include <vector>
#include <string>
#include <cstdio>

void even_odd_palindrome(std::vector<int>& vec, int num) {
    if (num < 1) {
        return;
    }

    vec.clear();
    vec.resize(2);

    vec[0] = num;
    vec[1] = num;

    if (num % 2 == 0) {
        vec[1] = num + 1;
    }

}

int main() {
    std::vector<int> numbers;
    int input = 10;

    even_odd_palindrome(numbers, input);

    for (int num : numbers) {
        printf("%d\n", num);
    }

    return 0;
}
```