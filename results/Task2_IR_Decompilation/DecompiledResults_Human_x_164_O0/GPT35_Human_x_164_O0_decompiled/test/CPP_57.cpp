```c
#include <vector>

bool monotonic(std::vector<float>& vec) {
    bool result = true;
    int i = 0;
    int j = 0;
    int k = 1;

    while (k < vec.size()) {
        if (vec[i] > vec[k]) {
            result = false;
            break;
        }
        i = k;
        k++;
    }

    if (result) {
        i = 0;
        j = 0;
        k = 1;
        while (k < vec.size()) {
            if (vec[i] < vec[k]) {
                result = false;
                break;
            }
            i = k;
            k++;
        }
    }

    return result;
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
