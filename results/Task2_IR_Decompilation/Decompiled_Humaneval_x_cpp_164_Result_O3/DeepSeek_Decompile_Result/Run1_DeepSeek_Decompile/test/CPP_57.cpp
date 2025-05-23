#include <vector>
using namespace std;

bool monotonicSt(const vector<float>* v) {
    if (v->empty()) {
        return false;
    }

    size_t size = v->size();
    size_t quarter = size / 4;

    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 0; i < quarter; ++i) {
        if (v->at(i) >= v->at(i + 1)) {
            increasing = false;
        }
        if (v->at(i) <= v->at(i + 1)) {
            decreasing = false;
        }
    }

    if (size % 4 != 0) {
        for (size_t i = quarter * 4; i < size - 1; ++i) {
            if (v->at(i) >= v->at(i + 1)) {
                increasing = false;
            }
            if (v->at(i) <= v->at(i + 1)) {
                decreasing = false;
            }
        }
    }

    return increasing || decreasing;
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
