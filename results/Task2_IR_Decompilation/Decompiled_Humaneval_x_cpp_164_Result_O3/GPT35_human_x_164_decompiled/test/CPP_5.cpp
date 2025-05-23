```c
#include <vector>
#include <iostream>

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    if (input.empty()) {
        return;
    }

    result.clear();

    for (auto it = input.begin(); it != input.end(); ++it) {
        result.push_back(*it);
        result.push_back(value);
    }

    result.pop_back();
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> result;
    
    intersperse(result, input, 0);

    for (const auto& num : result) {
        std::cout << num << " ";
    }
    
    std::cout << std::endl;

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
    assert (issame(intersperse({}, 7), {}));
    
    assert (issame(intersperse({5, 6, 3, 2}, 8),{5, 8, 6, 8, 3, 8, 2}));
    assert (issame(intersperse({2, 2, 2}, 2),{2, 2, 2, 2, 2}));
}