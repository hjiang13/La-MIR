#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

void maximum(std::vector<int>& result, const std::vector<int>& vec, int size) {
    if (size > vec.max_size()) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }
    
    std::vector<int> temp(vec.begin(), vec.end());
    std::sort(temp.begin(), temp.end());
    
    result = temp;
}

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    std::vector<int> result;
    
    try {
        maximum(result, vec, vec.size());
        
        for (int num : result) {
            std::cout << num << " ";
        }
    } catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }
    
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
    assert (issame(maximum({-3, -4, 5}, 3) , {-4, -3, 5}));
    assert (issame(maximum({4, -4, 4}, 2) , {4, 4}));
    assert (issame(maximum({-3, 2, 1, 2, -1, -2, 1}, 1) , {2}));
    assert (issame(maximum({123, -123, 20, 0 , 1, 2, -3}, 3) , {2, 20, 123}));
    assert (issame(maximum({-123, 20, 0 , 1, 2, -3}, 4) , {0, 1, 2, 20}));
    assert (issame(maximum({5, 15, 0, 3, -13, -8, 0}, 7) , {-13, -8, 0, 0, 3, 5, 15}));
    assert (issame(maximum({-1, 0, 2, 5, 3, -10}, 2) , {3, 5}));
    assert (issame(maximum({1, 0, 5, -7}, 1) , {5}));
    assert (issame(maximum({4, -4}, 2) , {-4, 4}));
    assert (issame(maximum({-10, 10}, 2) , {-10, 10}));
    assert (issame(maximum({1, 2, 3, -23, 243, -400, 0}, 0) , {}));
}
