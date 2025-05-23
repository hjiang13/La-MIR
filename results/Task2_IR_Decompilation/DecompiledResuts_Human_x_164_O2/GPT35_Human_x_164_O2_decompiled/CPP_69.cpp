```cpp
#include <vector>
#include <iostream>

void search(std::vector<int>& vec) {
    std::vector<int> temp;
    
    for (int i = 0; i < vec.size(); i++) {
        int current = vec[i];
        
        bool found = false;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == current) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            temp.push_back(current);
        }
    }
    
    for (int i = 0; i < temp.size(); i++) {
        std::cout << temp[i] << " ";
    }
}

int main() {
    std::vector<int> values = {1, 2, 3, 1, 2, 3, 4, 5};
    
    search(values);
    
    return 0;
}
```