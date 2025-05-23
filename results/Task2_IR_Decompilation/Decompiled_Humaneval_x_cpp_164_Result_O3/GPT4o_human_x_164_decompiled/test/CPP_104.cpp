#include <vector>
#include <stdexcept>
#include <algorithm>

void unique_digits(std::vector<int>& vec, const std::vector<int>& input) {
    vec.clear();
    if (input.empty()) return;
    
    std::vector<int> temp(input);
    std::sort(temp.begin(), temp.end());
    auto last = std::unique(temp.begin(), temp.end());
    temp.erase(last, temp.end());
    
    for (const auto& elem : temp) {
        if (elem >= 0 && elem <= 9) {
            vec.push_back(elem);
        }
    }
}

int main() {
    std::vector<int> result;
    std::vector<int> input = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 0, 1};
    unique_digits(result, input);
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
    assert (issame(unique_digits({15, 33, 1422, 1}) , {1, 15, 33}));
    assert (issame(unique_digits({152, 323, 1422, 10}) , {}));
    assert (issame(unique_digits({12345, 2033, 111, 151}) , {111, 151}));
    assert (issame(unique_digits({135, 103, 31}) , {31, 135}));
}
