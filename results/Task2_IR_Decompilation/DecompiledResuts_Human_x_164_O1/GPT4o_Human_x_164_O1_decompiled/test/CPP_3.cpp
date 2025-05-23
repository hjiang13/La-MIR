#include <vector>

extern "C" {
    long long llvm_umax(long long a, long long b);
}

bool below_zero(std::vector<int> &vec) {
    int *data = vec.data();
    int size = vec.size();
    
    if (size == 0) return false;

    long long count = 0;
    long long maxCount = (size + 3) / 4; // Equivalent to shifting right by 2

    for (int i = 0; i < size; i++) {
        int value = data[i];
        if (value < 0) return true;
        count++;
        if (count >= maxCount) break;
    }

    return count < maxCount;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_zero({}) == false);
    assert (below_zero({1, 2, -3, 1, 2, -3}) == false);
    assert (below_zero({1, 2, -4, 5, 6}) == true);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -4}) == false);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -5}) == true);
    assert (below_zero({1, -2, 2, -2, 5, -5, 4, -4}) == true);
}