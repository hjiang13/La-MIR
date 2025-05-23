```c
#include <vector>
#include <string>
#include <cstdio>
#include <cstdarg>

void even_odd_palindrome(std::vector<int>& result, int n) {
    if (n < 1) {
        result.clear();
        result.push_back(0);
        result.push_back(0);
        result.push_back(0);
        return;
    }

    result.clear();
    result.push_back(n);
    result.push_back(0);
    result.push_back(0);
}

int main() {
    std::vector<int> vec;
    int num = 10;

    even_odd_palindrome(vec, num);

    for (int i = 0; i < vec.size(); i++) {
        printf("%d\n", vec[i]);
    }

    return 0;
}
```