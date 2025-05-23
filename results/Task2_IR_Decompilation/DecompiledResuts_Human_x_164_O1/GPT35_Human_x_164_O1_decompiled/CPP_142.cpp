```c++
#include <vector>

int sum_squares(std::vector<int> &vec) {
    int sum = 0;
    int size = vec.size();
    
    for (int i = 0; i < size; i++) {
        int element = vec[i];
        if (i % 3 == 0) {
            sum += element * element;
        } else {
            sum += element * element * element;
        }
    }
    
    return sum;
}
```