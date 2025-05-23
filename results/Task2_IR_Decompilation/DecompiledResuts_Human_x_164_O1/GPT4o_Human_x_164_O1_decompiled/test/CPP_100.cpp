#include <vector>
#include <stdexcept>
#include <iostream>

void make_a_pile(std::vector<int>& vec, int size) {
    if (size < 1) return;

    vec.resize(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = i + 2;  // Fill the vector with values starting from 2
    }
}

int main() {
    std::vector<int> my_vector;
    make_a_pile(my_vector, 10);

    for (const int& value : my_vector) {
        std::cout << value << " ";
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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}
