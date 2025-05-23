#include <cstdlib>

bool isCube(int n) {
    int abs_n = std::abs(n);
    int i = 0;
    while (true) {
        int cube = i * i * i;
        if (cube > abs_n) {
            break;
        }
        ++i;
    }
    return (i * i * i == abs_n);
}

// Example usage:
// int main() {
//     // Test cases
//     bool result1 = isCube(8);   // Should return true (2^3)
//     bool result2 = isCube(9);   // Should return false
//     return 0;
// }

#undef NDEBUG
#include<assert.h>
int main(){
    assert (iscuber(1) == true);
    assert (iscuber(2) == false);
    assert (iscuber(-1) == true);
    assert (iscuber(64) == true);
    assert (iscuber(180) == false);
    assert (iscuber(1000) == true);
    assert (iscuber(0) == true);
    assert (iscuber(1729) == false);
}
