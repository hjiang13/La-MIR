#include <vector>
#include <algorithm>
#include <stdexcept>

void unique_digits(std::vector<int>& result, const std::vector<int>& input) {
    int index = 0;
    bool isValid = false;
    
    while (index < input.size()) {
        int digit = input[index];
        isValid = true;
        
        if (digit % 2 == 0) {
            isValid = false;
        }
        
        if (isValid) {
            result.push_back(digit);
        }
        
        index++;
    }

    std::sort(result.begin(), result.end());
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
