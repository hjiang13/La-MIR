```c++
#include <vector>

int add(std::vector<int> *vec) {
    int result = 0;
    int index = 0;
    
    while (index * 2 + 1 < vec->size()) {
        int element = (*vec)[index * 2 + 1];
        
        if (element % 2 == 0) {
            result += element;
        }
        
        index++;
    }
    
    return result;
}
```