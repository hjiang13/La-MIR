```c
#include <vector>

bool move_one_ball(std::vector<int> &v) {
    int* ptr1 = v._M_impl._M_start._M_p;
    int* ptr2 = v._M_impl._M_finish._M_p;
    
    int diff = ptr1 - ptr2;
    int count = diff / 4;
    
    if (diff == 0) {
        return true;
    }
    
    if (count > 1) {
        int elem = *ptr2;
        
        if (count - 1 < 8) {
            int mask = count - 1 | 1;
            std::vector<int> temp = {0, 0, 0, elem};
            
            for (int i = 1; i < 8; i++) {
                int* ptr = ptr2 + i;
                std::vector<int> vec1(ptr, ptr + 4);
                std::vector<int> vec2(ptr + 4, ptr + 8);
                
                for (int j = 0; j < 4; j++) {
                    if (vec1[j] < temp[j]) {
                        temp[j]++;
                    }
                    
                    if (vec2[j] < temp[j]) {
                        temp[j]++;
                    }
                }
            }
            
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += temp[i];
            }
            
            return sum == 0;
        }
    }
    
    int prev = *ptr2;
    
    for (int i = count - 1; i > 0; i--) {
        int val = *(ptr2 - i);
        if (val > prev) {
            count++;
        }
        prev = val;
    }
    
    return count < 2;
}
```