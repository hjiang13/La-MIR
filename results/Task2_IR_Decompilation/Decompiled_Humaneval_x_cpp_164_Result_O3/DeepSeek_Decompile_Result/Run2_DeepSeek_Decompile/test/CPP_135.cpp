#include <vector>
using namespace std;

int can_arrange(vector<int> vec) {
    if (vec.empty()) {
        return -1;
    }

    int n = vec.size();
    int mid = (n / 2) + (n % 2);
    int max = INT32_MAX;
    int min = INT32_MIN;

    for (int i = 0; i < mid; i++) {
        if (i > max) {
            max = i;
        }
        if (i < min) {
            min = i;
        }
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (i == max || i == min) {
            continue;
        }
        if (vec[i] == i) {
            found = true;
            break;
        }
    }

    if (found) {
        return 1;
    } else {
        return -1;
    }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (can_arrange({1,2,4,3,5})==3);
    assert (can_arrange({1,2,4,5})==-1);
    assert (can_arrange({1,4,2,5,6,7,8,9,10})==2);
    assert (can_arrange({4,8,5,7,3})==4);
    assert (can_arrange({})==-1);
}
