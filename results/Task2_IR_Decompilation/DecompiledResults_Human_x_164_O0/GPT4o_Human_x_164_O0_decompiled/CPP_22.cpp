```cpp
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
```