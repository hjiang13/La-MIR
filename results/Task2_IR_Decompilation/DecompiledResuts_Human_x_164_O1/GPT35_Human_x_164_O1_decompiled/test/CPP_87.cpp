#include <vector>

std::vector<int> get_row(std::vector<std::vector<int>>* v, int i) {
    std::vector<int> result;
    result.resize(v->at(0).at(0).size());
    for (int j = 0; j < v->at(i).at(0).size(); j++) {
        result[j] = v->at(i).at(0).at(j);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> row = get_row(&v, 1);
    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<vector<int>> a,vector<vector<int>> b){
    if (a.size()!=b.size()) return false;

    for (int i=0;i<a.size();i++)
    {
        if (a[i].size()!=b[i].size()) return false;
        for (int j=0;j<a[i].size();j++)
            if (a[i][j]!=b[i][j]) return false;
    }
    return true;
}
int main(){
    assert (issame(get_row({
        {1,2,3,4,5,6},
        {1,2,3,4,1,6},
        {1,2,3,4,5,1}}, 1) , {{0, 0}, {1, 4}, {1, 0}, {2, 5}, {2, 0}}));
    assert (issame(get_row({
        {1,2,3,4,5,6},
        {1,2,3,4,5,6},
        {1,2,3,4,5,6},
        {1,2,3,4,5,6},
        {1,2,3,4,5,6},
        {1,2,3,4,5,6}}, 2) , {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}}));
    assert (issame(get_row({
        {1,2,3,4,5,6},
        {1,2,3,4,5,6},
        {1,1,3,4,5,6},
        {1,2,1,4,5,6},
        {1,2,3,1,5,6},
        {1,2,3,4,1,6},
        {1,2,3,4,5,1}
    }, 1) , {{0, 0}, {1, 0}, {2, 1}, {2, 0}, {3, 2}, {3, 0}, {4, 3}, {4, 0}, {5, 4}, {5, 0}, {6, 5}, {6, 0}}));
    assert (issame(get_row({}, 1) , {}));
    assert (issame(get_row({{1}}, 2) , {}));
    assert (issame(get_row({{}, {1}, {1, 2, 3}}, 3) , {{2, 2}}));
}
