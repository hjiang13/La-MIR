#include <vector>
#include <iostream>

void count_up_to(std::vector<int>& vec, int n) {
    vec.clear();
    for (int i = 0; i < n; ++i) {
        vec.push_back(i);
    }
}

int main() {
    std::vector<int> vec;
    count_up_to(vec, 10);
    for (int i : vec) {
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
    assert (issame(count_up_to(5) , {2,3}));
    assert (issame(count_up_to(6) , {2,3,5}));
    assert (issame(count_up_to(7) , {2,3,5}));
    assert (issame(count_up_to(10) , {2,3,5,7}));
    assert (issame(count_up_to(0) , {}));
    assert (issame(count_up_to(22) , {2,3,5,7,11,13,17,19}));
    assert (issame(count_up_to(1) , {}));
    assert (issame(count_up_to(18) , {2,3,5,7,11,13,17}));
    assert (issame(count_up_to(47) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}));
    assert (issame(count_up_to(101) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}));
}
