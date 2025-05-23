```cpp
#include <iostream>
#include <vector>

void unique_digits(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    size_t input_size = input.size();
    if (input_size == 0) {
        return;
    }

    int prev = input[0] % 10;
    result.push_back(prev);

    for (size_t i = 1; i < input_size; i++) {
        int curr = input[i] % 10;
        if (curr != prev) {
            result.push_back(curr);
            prev = curr;
        }
    }
}

int main() {
    std::vector<int> input = {1, 22, 333, 4444, 55555, 666666, 7777777, 88888888, 999999999};
    std::vector<int> result;
    unique_digits(result, input);

    for (int i : result) {
        std::cout << i << " ";
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
    assert (issame(unique_digits({15, 33, 1422, 1}) , {1, 15, 33}));
    assert (issame(unique_digits({152, 323, 1422, 10}) , {}));
    assert (issame(unique_digits({12345, 2033, 111, 151}) , {111, 151}));
    assert (issame(unique_digits({135, 103, 31}) , {31, 135}));
}
