#include <vector>

bool will_it_fly(std::vector<int>& vec, int val) {
    int index = 0;
    int sum = 0;

    while (index < vec.size()) {
        int current_val = vec[index];
        int next_val = vec[vec.size() - 1 - index];

        if (current_val != next_val) {
            return false;
        } else {
            sum += current_val;
        }

        index++;
    }

    return sum > val;
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
