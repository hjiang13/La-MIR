#include <vector>

bool below_zero(std::vector<int> &vec) {
    bool result = false;
    int sum = 0;
    int index = 0;
    
    while (index < vec.size()) {
        sum += vec[index];
        if (sum < 0) {
            result = true;
            break;
        }
        index++;
    }
    
    return result;
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