#include <vector>
#include <algorithm>

std::vector<int> unique_digits(const std::vector<int>& input) {
    std::vector<int> result;
    for (int num : input) {
        bool is_unique = true;
        int temp = num;
        if (temp == 0) {
            is_unique = false;
        }
        while (temp > 0 && is_unique) {
            if (temp % 2 == 0) {
                is_unique = false;
            }
            temp /= 10;
        }
        if (is_unique) {
            result.push_back(num);
        }
    }
    std::sort(result.begin(), result.end());
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
    assert (issame(unique_digits({15, 33, 1422, 1}) , {1, 15, 33}));
    assert (issame(unique_digits({152, 323, 1422, 10}) , {}));
    assert (issame(unique_digits({12345, 2033, 111, 151}) , {111, 151}));
    assert (issame(unique_digits({135, 103, 31}) , {31, 135}));
}
