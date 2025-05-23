#include <iostream>
#include <vector>

using namespace std;

bool will_it_fly(vector<int> vec, int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;

    while (i < vec.size()) {
        j = i + n - 1;
        if (j >= vec.size()) {
            break;
        }
        k = vec[i];
        l = vec[j];
        m = k + l;
        p = m / 2;
        q = p + 1;
        r = q + 1;
        s = r + 1;
        t = s + 1;
        u = t + 1;
        v = u + 1;
        w = v + 1;
        x = w + 1;
        y = x + 1;
        z = y + 1;
        if (z >= vec.size()) {
            break;
        }
        if (vec[z] == k) {
            return true;
        }
        i++;
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
