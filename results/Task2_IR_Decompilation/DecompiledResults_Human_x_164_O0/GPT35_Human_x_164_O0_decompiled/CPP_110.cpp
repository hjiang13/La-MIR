```cpp
#include <iostream>
#include <string>
#include <vector>

void exchange(std::__cxx11::basic_string& result, std::vector<int>& vec1, std::vector<int>& vec2) {
    int index1 = 0;
    int index2 = 0;
    
    while (index1 < vec1.size()) {
        int value = vec1[index1];
        if (value % 2 == 0) {
            index1++;
        } else {
            index1++;
            index2++;
        }
    }
    
    if (index2 < vec2.size()) {
        result = "YES";
    } else {
        result = "NO";
    }
}

int getSize(std::vector<int>& vec) {
    return vec.size();
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {6, 7, 8, 9, 10};
    std::__cxx11::basic_string result;
    
    exchange(result, vec1, vec2);
    
    std::cout << "Result: " << result << std::endl;
    
    std::cout << "Size of vec1: " << getSize(vec1) << std::endl;
    std::cout << "Size of vec2: " << getSize(vec2) << std::endl;
    
    return 0;
}
```