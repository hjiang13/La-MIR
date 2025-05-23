#include <iostream>
#include <vector>
#include <list>
#include <boost/any.hpp>

void filter_integers(std::vector<int>& vec, const std::list<boost::any>& lst) {
    vec.clear();
    for (const auto& item : lst) {
        if (item.type() == typeid(int)) {
            vec.push_back(boost::any_cast<int>(item));
        }
    }
}

int main() {
    std::list<boost::any> lst = {1, 2.5, 3, "text", boost::any(4)};
    std::vector<int> vec;
    filter_integers(vec, lst);

    for (const int& i : vec) {
        std::cout << i << std::endl;
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
    assert (issame(filter_integers({}),{}));

    assert (issame(filter_integers({4,  {},23.2, 9, string("adasd")}) ,{4, 9}));
    assert (issame(filter_integers({3, 'c', 3, 3, 'a', 'b'}) ,{3, 3, 3}));
}