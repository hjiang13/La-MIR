```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<std::vector<int>> get_matrix_triples(int n) {
    std::vector<std::vector<int>> result;
    if (n < 1) return result;

    result.resize(n);
    for (int i = 0; i < n; ++i) {
        result[i].resize(3, 0);
    }

    for (int i = 0; i < n; ++i) {
        result[i][0] = i * 2; // Example logic for filling the vector
        result[i][1] = i * 3; // Example logic for filling the vector
        result[i][2] = i * 4; // Example logic for filling the vector
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter the size of the matrix: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix = get_matrix_triples(n);
    
    for (const auto &row : matrix) {
        for (const auto &elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
```