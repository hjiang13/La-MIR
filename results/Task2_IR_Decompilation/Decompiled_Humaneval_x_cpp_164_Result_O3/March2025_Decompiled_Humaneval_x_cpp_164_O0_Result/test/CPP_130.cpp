#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <iterator>

void tri(std::vector<int>& result, int n) {
    std::vector<int> temp({1, 3});
    if (n == 0) {
        result = std::vector<int>({1});
    } else {
        result = temp;
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) {
                int value = 1 + i / 2;
                temp.push_back(value);
            } else {
                int value1 = temp[i - 1];
                int value2 = temp[i - 2];
                int value = value1 + value2 + 1 + (i + 1) / 2;
                temp.push_back(value);
            }
        }
        result = std::move(temp);
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
