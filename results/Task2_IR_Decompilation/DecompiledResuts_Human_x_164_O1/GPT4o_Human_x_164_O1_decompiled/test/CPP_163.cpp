#include <vector>
#include <iostream>
#include <stdexcept>

void generate_integers(std::vector<int>& vec, int n, int m) {
    int start = std::min(n, m);
    int end = std::max(n, m);
    vec.clear();
    
    for (int i = start; i < end; ++i) {
        vec.push_back(i);
        if (vec.size() >= 10) {
            break;
        }
    }
}

int main() {
    std::vector<int> vec;
    generate_integers(vec, 5, 15);
    
    for (int num : vec) {
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
    assert (issame(generate_integers(2, 10) , {2, 4, 6, 8}));
    assert (issame(generate_integers(10, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(132, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(17,89) , {}));
}
