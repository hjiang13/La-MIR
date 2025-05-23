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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_threshold({1, 2, 4, 10}, 100));
    assert (not(below_threshold({1, 20, 4, 10}, 5)));
    assert (below_threshold({1, 20, 4, 10}, 21));
    assert (below_threshold({1, 20, 4, 10}, 22));
    assert (below_threshold({1, 8, 4, 10}, 11));
    assert (not(below_threshold({1, 8, 4, 10}, 10)));
}
