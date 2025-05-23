```cpp
#include <vector>
#include <stdexcept>

void minPath(std::vector<std::vector<int>>& result, const std::vector<std::vector<int>>& input, int size) {
    int i = 0, j = 0;
    int end_i = input.size(), end_j = input[0].size();
    int count = 0;

    while (i < end_i && j < end_j) {
        result.push_back(input[i][j]);
        if (input[i][j] == 1) {
            count++;
        }

        if (count > 0) {
            j++;
            if (j == end_j) {
                j--;
                i++;
            }
        } else {
            i++;
        }
    }

    while (i < end_i) {
        result.push_back(input[i][j]);
        if (input[i][j] == 1) {
            count++;
        }
        i++;
    }

    while (j < end_j) {
        result.push_back(input[i][j]);
        if (input[i][j] == 1) {
            count++;
        }
        j++;
    }
}

int main() {
    std::vector<std::vector<int>> input = {{0, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    std::vector<std::vector<int>> result;

    minPath(result, input, 0);

    return 0;
}
```