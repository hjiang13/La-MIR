#include <iostream>
#include <vector>
#include <stdexcept>

void pluck(std::vector<int>& vec1, const std::vector<int>& vec2) {
    int* ptr1 = vec1.data();
    int* ptr2 = vec2.data();
    
    if (ptr1 == ptr2) {
        return;
    }

    size_t index = 0;
    while (index < vec1.size()) {
        int value = ptr1[index];
        if ((value & 1) == 0) {
            if (index < vec2.size()) {
                vec1.push_back(value);
            }
        }
        index++;
    }
}

int main() {
    std::vector<int> vec1;
    std::vector<int> vec2 = {1, 2, 3, 4, 5};

    pluck(vec1, vec2);
    
    for (int val : vec1) {
        std::cout << val << std::endl;
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
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
