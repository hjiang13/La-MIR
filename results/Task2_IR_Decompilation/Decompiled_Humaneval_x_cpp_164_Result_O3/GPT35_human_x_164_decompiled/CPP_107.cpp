```cpp
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

void even_odd_palindrome(std::vector<int>& result, int size) {
    if (size < 1) {
        return;
    }

    std::memset(result.data(), 0, 24);

    int* ptr1 = static_cast<int*>(std::malloc(8));
    *ptr1 = 0;
    int* ptr2 = ptr1 + 1;
    *ptr2 = 0;

    result.push_back(*ptr1);
    result.push_back(*ptr2);

    std::memcpy(result.data() + 4, ptr1, 4);

    std::free(ptr1);
}

int main() {
    std::vector<int> vec;
    even_odd_palindrome(vec, 10);

    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }

    return 0;
}
```