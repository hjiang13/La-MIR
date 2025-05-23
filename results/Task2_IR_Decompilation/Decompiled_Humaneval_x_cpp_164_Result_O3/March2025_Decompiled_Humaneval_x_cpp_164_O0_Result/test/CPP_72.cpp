#include <vector>

bool will_it_fly(std::vector<int> vec, int threshold) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] != vec[vec.size() - 1 - i]) {
            return false;
        }
        sum += vec[i];
    }
    return sum <= threshold;
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
