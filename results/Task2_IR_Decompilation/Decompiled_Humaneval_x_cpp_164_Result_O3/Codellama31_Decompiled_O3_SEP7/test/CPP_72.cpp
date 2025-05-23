#include <vector>

bool will_it_fly(std::vector<int> vec, int input) {
    int size = vec.size();
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vec[i];
        if (sum == input) {
            return true;
        }
    }
    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (will_it_fly({3, 2, 3}, 9)==true);
    assert (will_it_fly({1, 2}, 5) == false);
    assert (will_it_fly({3}, 5) == true);
    assert (will_it_fly({3, 2, 3}, 1) == false);
    assert (will_it_fly({1, 2, 3}, 6) ==false);
    assert (will_it_fly({5}, 5) == true);
}
