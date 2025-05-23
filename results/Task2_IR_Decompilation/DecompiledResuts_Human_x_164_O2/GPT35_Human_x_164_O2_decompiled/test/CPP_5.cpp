```c++
#include <vector>
#include <stdexcept>

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    result.clear();
    const int* begin = &input[0];
    const int* end = begin + input.size();
    if (begin == end) {
        return;
    }
    result.reserve(input.size() * 2 - 1);
    result.push_back(*begin);
    for (++begin; begin != end; ++begin) {
        result.push_back(value);
        result.push_back(*begin);
    }
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> output;
    
    intersperse(output, input, 0);
    
    for (int num : output) {
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