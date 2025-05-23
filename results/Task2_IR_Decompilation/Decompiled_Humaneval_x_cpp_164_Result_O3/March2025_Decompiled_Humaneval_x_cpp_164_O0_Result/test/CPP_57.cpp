#include <vector>

bool monotonic(const std::vector<float>& vec) {
    bool increasing = false;
    bool decreasing = false;

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > vec[i - 1]) {
            increasing = true;
        }
        if (vec[i] < vec[i - 1]) {
            decreasing = true;
        }
    }

    return !(increasing && decreasing);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (monotonic({1, 2, 4, 10}) == true);
    assert (monotonic({1, 2, 4, 20}) == true);
    assert (monotonic({1, 20, 4, 10}) == false);
    assert (monotonic({4, 1, 0, -10}) == true);
    assert (monotonic({4, 1, 1, 0}) == true);
    assert (monotonic({1, 2, 3, 2, 5, 60}) == false);
    assert (monotonic({1, 2, 3, 4, 5, 60}) == true);
    assert (monotonic({9, 9, 9, 9}) == true);
}
