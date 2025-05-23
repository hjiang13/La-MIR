#include <iostream>
#include <vector>

using namespace std;

int max_fill(vector<vector<int>>& vec, int n) {
    int max_fill = 0;
    for (int i = 0; i < n; i++) {
        int fill = 0;
        for (int j = 0; j < n; j++) {
            fill += vec[i][j];
        }
        max_fill = max(max_fill, fill);
    }
    return max_fill;
}

int main() {
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    cout << max_fill(vec, n) << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (max_fill({{0,0,1,0}, {0,1,0,0}, {1,1,1,1}}, 1) == 6);
    assert (max_fill({{0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}}, 2) == 5);
    assert (max_fill({{0,0,0}, {0,0,0}}, 5) == 0);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 2) == 4);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 9) == 2);
}
