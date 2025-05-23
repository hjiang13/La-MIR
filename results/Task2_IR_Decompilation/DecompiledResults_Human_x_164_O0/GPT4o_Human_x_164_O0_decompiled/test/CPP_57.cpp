#include <vector>

bool monotonic(std::vector<float>& vec) {
    int size = vec.size();
    int increasing = 0;
    int decreasing = 0;

    for (int i = 1; i < size; i++) {
        if (vec[i] > vec[i - 1]) {
            increasing = 1;
        } else if (vec[i] < vec[i - 1]) {
            decreasing = 1;
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
