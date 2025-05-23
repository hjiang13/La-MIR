```cpp
#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

void order_by_points(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> temp_vec;
    std::string str;
    int count = 0;
    
    int* start1 = vec1.data();
    int* end1 = start1 + vec1.size();
    int* start2 = vec2.data();
    
    if (end1 == start1) return; // if vec1 is empty
    
    for (int* it = start1; it < end1; ++it) {
        if (*it > 0) {
            temp_vec.push_back(*it);
            count++;
        }
    }
    
    if (count > 0) {
        int abs_count = abs(count);
        str.resize(16);
        int written = snprintf(&str[0], str.size(), "%d", abs_count);
        
        if (written >= 0) {
            for (int i = 0; i < count; i++) {
                vec2.push_back(temp_vec[i]);
            }
        }
    }
}
```