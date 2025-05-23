#include <vector>
#include <stdexcept>
#include <cstring>

void minPath(std::vector<int>& result, const std::vector<std::vector<int>>& graph, int size) {
    if (size <= 0) {
        return;
    }

    result.clear();
    result.resize(size, 0);
    
    for (int i = 0; i < size; ++i) {
        int min_value = INT_MAX;
        int min_index = -1;
        
        for (int j = 0; j < graph[i].size(); ++j) {
            if (graph[i][j] < min_value) {
                min_value = graph[i][j];
                min_index = j;
            }
        }
        
        if (min_index != -1) {
            result[i] = min_value;
        } else {
            throw std::length_error("minPath: invalid graph");
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
