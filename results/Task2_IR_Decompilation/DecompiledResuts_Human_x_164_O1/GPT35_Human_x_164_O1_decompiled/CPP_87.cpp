```c
#include <vector>

std::vector<int> get_row(std::vector<std::vector<int>>* v, int i) {
    std::vector<int> result;
    result.resize(v->at(0).at(0).size());
    for (int j = 0; j < v->at(i).at(0).size(); j++) {
        result[j] = v->at(i).at(0).at(j);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> row = get_row(&v, 1);
    return 0;
}
```