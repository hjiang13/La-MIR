#include <vector>
#include <cmath>
#include <stdexcept>

void sort_array(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> temp;
    for (size_t i = 0; i < input.size(); ++i) {
        int value = std::abs(input[i]);
        int sum = 0;
        while (value > 0) {
            sum += value % 2;
            value /= 2;
        }
        temp.push_back(sum);
    }

    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 1; j < input.size(); ++j) {
            if (temp[j] < temp[j - 1] || (temp[j] == temp[j - 1] && input[j] < input[j - 1])) {
                std::swap(temp[j], temp[j - 1]);
                std::swap(result[j], result[j - 1]);
            }
        }
    }
    result = std::move(temp);
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
    assert (issame(sort_array({1,5,2,3,4}) , {1, 2, 4, 3, 5}));
    assert (issame(sort_array({-2,-3,-4,-5,-6}) , {-4, -2, -6, -5, -3}));
    assert (issame(sort_array({1,0,2,3,4}) , {0, 1, 2, 4, 3}));
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({2,5,77,4,5,3,5,7,2,3,4}) , {2, 2, 4, 4, 3, 3, 5, 5, 5, 7, 77}));
    assert (issame(sort_array({3,6,44,12,32,5}) , {32, 3, 5, 6, 12, 44}));
    assert (issame(sort_array({2,4,8,16,32}) , {2, 4, 8, 16, 32}));
    assert (issame(sort_array({2,4,8,16,32}) , {2, 4, 8, 16, 32}));
}
