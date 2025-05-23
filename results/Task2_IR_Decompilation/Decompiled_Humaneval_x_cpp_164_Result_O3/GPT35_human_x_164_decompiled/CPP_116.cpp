```cpp
#include <vector>

void sort_array(std::vector<int>& output, std::vector<int>& input) {
    int size = input.size();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (input[j] > input[j + 1]) {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }

    output = input;
}

int main() {
    std::vector<int> input = {4, 2, 7, 1, 5};
    std::vector<int> output;

    sort_array(output, input);

    return 0;
}
```