#include <vector>
#include <stdexcept>
#include <algorithm>

std::vector<int> minPath(std::vector<std::vector<int>>& grid, int n) {
    std::vector<int> result;
    int minValue = grid[0][0];
    int minRow = 0, minCol = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 1) {
                minRow = i;
                minCol = j;
            }
        }
    }

    int size = grid.size() * grid[0].size();
    int minPathValue = size;

    if (minRow > 0) {
        int value = grid[minRow - 1][minCol];
        if (value < minPathValue) {
            minPathValue = value;
        }
    }

    if (minRow < grid.size() - 1) {
        int value = grid[minRow + 1][minCol];
        if (value < minPathValue) {
            minPathValue = value;
        }
    }

    if (minCol > 0) {
        int value = grid[minRow][minCol - 1];
        if (value < minPathValue) {
            minPathValue = value;
        }
    }

    if (minCol < grid[0].size() - 1) {
        int value = grid[minRow][minCol + 1];
        if (value < minPathValue) {
            minPathValue = value;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            result.push_back(1);
        } else {
            result.push_back(minPathValue);
        }
    }

    return result;
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
    assert (issame(minPath({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 3) , {1, 2, 1}));
    assert (issame(minPath({{5, 9, 3}, {4, 1, 6}, {7, 8, 2}}, 1) , {1}));
    assert (issame(minPath({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 4) , {1, 2, 1, 2}));
    assert (issame(minPath({{6, 4, 13, 10}, {5, 7, 12, 1}, {3, 16, 11, 15}, {8, 14, 9, 2}}, 7) , {1, 10, 1, 10, 1, 10, 1}));
    assert (issame(minPath({{8, 14, 9, 2}, {6, 4, 13, 15}, {5, 7, 1, 12}, {3, 10, 11, 16}}, 5) , {1, 7, 1, 7, 1}));
    assert (issame(minPath({{11, 8, 7, 2}, {5, 16, 14, 4}, {9, 3, 15, 6}, {12, 13, 10, 1}}, 9) , {1, 6, 1, 6, 1, 6, 1, 6, 1}));
    assert (issame(minPath({{12, 13, 10, 1}, {9, 3, 15, 6}, {5, 16, 14, 4}, {11, 8, 7, 2}}, 12) , {1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6}));
    assert (issame(minPath({{2, 7, 4}, {3, 1, 5}, {6, 8, 9}}, 8) , {1, 3, 1, 3, 1, 3, 1, 3}));
    assert (issame(minPath({{6, 1, 5}, {3, 8, 9}, {2, 7, 4}}, 8) , {1, 5, 1, 5, 1, 5, 1, 5}));
    assert (issame(minPath({{1, 2}, {3, 4}}, 10) , {1, 2, 1, 2, 1, 2, 1, 2, 1, 2}));
    assert (issame(minPath({{1, 3}, {3, 2}}, 10) , {1, 3, 1, 3, 1, 3, 1, 3, 1, 3}));
}
