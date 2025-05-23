```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void minPath(std::vector<int>& result, const std::vector<std::vector<int>>& graph, int size) {
    if (size <= 0) {
        return;
    }

    result.clear();
    result.resize(size, 0);
    
    for (int i = 0; i < size; ++i) {
        int min_value = INT_MAX;
        int min_index = -1;
        
        for (int j = 0; j < graph[i].size(); ++j) {
            if (graph[i][j] < min_value) {
                min_value = graph[i][j];
                min_index = j;
            }
        }
        
        if (min_index != -1) {
            result[i] = min_value;
        } else {
            throw std::length_error("minPath: invalid graph");
        }
    }
}
```