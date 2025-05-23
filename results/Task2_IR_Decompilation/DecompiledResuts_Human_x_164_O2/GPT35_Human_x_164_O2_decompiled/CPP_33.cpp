```c++
#include <vector>
#include <iostream>

void sort_third(std::vector<int>& result, std::vector<int>& input) {
    int* begin = &input[0];
    int* end = &input[input.size()];

    if (begin == end) {
        return;
    }

    int* current = begin;
    int* next = begin + 1;

    while (next != end) {
        if (*current < *next) {
            int temp = *current;
            *current = *next;
            *next = temp;
        }

        current++;
        next++;
    }

    result = input;
}

int main() {
    std::vector<int> input = {3, 2, 1};
    std::vector<int> result;

    sort_third(result, input);

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
```