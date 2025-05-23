#include <vector>
#include <stdexcept>

void minPath(std::vector<std::vector<int>>& result, const std::vector<std::vector<int>>& input, int size) {
    int i = 0, j = 0;
    int end_i = input.size(), end_j = input[0].size();
    int count = 0;

    while (i < end_i && j < end_j) {
        result.push_back(input[i][j]);
        if (input[i][j] == 1) {
            count++;
        }

        if (count > 0) {
            j++;
            if (j == end_j) {
                j--;
                i++;
            }
        } else {
            i++;
        }
    }

    while (i < end_i) {
        result.push_back(input[i][j]);
        if (input[i][j] == 1) {
            count++;
        }
        i++;
    }

    while (j < end_j) {
        result.push_back(input[i][j]);
        if (input[i][j] == 1) {
            count++;
        }
        j++;
    }
}

int main() {
    std::vector<std::vector<int>> input = {{0, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    std::vector<std::vector<int>> result;

    minPath(result, input, 0);

    return 0;
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
