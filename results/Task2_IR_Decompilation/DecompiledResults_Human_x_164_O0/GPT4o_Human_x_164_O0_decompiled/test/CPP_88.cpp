#include <vector>
#include <algorithm>

void sort_array(std::vector<int> &vec) {
    if (vec.size() == 0) {
        return;
    }

    int temp1 = vec[0];
    int temp2 = vec[vec.size() - 1];

    if ((temp1 + temp2) % 2 == 1) {
        std::sort(vec.begin(), vec.end());
    } else {
        std::vector<int> tempVec(vec);
        std::sort(tempVec.begin(), tempVec.end());
        vec = tempVec;
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({5}) , {5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5}) , {0, 1, 2, 3, 4, 5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5, 6}) , {6, 5, 4, 3, 2, 1, 0}));
    assert (issame(sort_array({2, 1}) , {1, 2}));
    assert (issame(sort_array({15, 42, 87, 32 ,11, 0}) , {0, 11, 15, 32, 42, 87}));
    assert (issame(sort_array({21, 14, 23, 11}) , {23, 21, 14, 11}));
}
