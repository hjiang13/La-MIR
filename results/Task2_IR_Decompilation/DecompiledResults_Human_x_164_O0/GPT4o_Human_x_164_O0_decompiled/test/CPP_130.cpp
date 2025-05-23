#include <vector>
#include <initializer_list>
#include <stdexcept>

void trii(std::vector<int>& vec, int n) {
    std::vector<int> temp;
    std::initializer_list<int> initList = { 1, 3 };
    temp = std::vector<int>(initList);

    if (n == 0) {
        vec.push_back(1);
        return;
    }

    for (int i = 0; i < n; ++i) {
        int count = i + 1;
        if (count % 2 == 0) {
            vec.push_back(count / 2);
        } else {
            int val1 = temp[count / 2];
            int val2 = temp[count / 2 - 1];
            vec.push_back(val1 + val2 + 1);
        }
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
    assert (issame(tri(3) , {1, 3, 2, 8}));
    assert (issame(tri(4) , {1, 3, 2, 8, 3}));
    assert (issame(tri(5) , {1, 3, 2, 8, 3, 15}));
    assert (issame(tri(6) , {1, 3, 2, 8, 3, 15, 4}));
    assert (issame(tri(7) , {1, 3, 2, 8, 3, 15, 4, 24}));
    assert (issame(tri(8) , {1, 3, 2, 8, 3, 15, 4, 24, 5}));
    assert (issame(tri(9) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35}));
    assert (issame(tri(20) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11}));
    assert (issame(tri(0) , {1}));
    assert (issame(tri(1) , {1, 3}));
}
