```cpp
#include <vector>
#include <algorithm>

extern "C" {
    int below_threshold(std::vector<int>* vec, int threshold) {
        auto* data = vec->_Mypair._Myval2._Myfirst;
        auto* end = vec->_Mypair._Myval2._Myend;

        auto size = (end - data) / 4;
        if (size == 0) return true;

        size = std::max(size, 1LL);
        bool result = true;

        for (int i = 0; i < size; ++i) {
            if (data[i] < threshold) {
                result = false;
                break;
            }
        }
        
        return result;
    }
}
```