#include <vector>

bool monotonic(std::vector<float> const& vec) {
    if (vec.size() < 2) {
        return true;
    }
    int count = 0;
    float prev = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > prev) {
            count++;
        } else if (vec[i] < prev) {
            count++;
        }
        prev = vec[i];
    }
    return count != 2;
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
