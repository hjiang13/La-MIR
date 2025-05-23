```cpp
#include <vector>
#include <list>
#include <boost/any.hpp>
#include <boost/exception/all.hpp>
#include <cstring>
#include <stdexcept>

class bad_any_cast : public std::bad_cast {
public:
    const char* what() const noexcept override {
        return "boost::bad_any_cast: failed conversion using boost::any_cast";
    }
};

void filter_integers(std::vector<int>& vec, const std::list<boost::any>& lst) {
    for (const auto& item : lst) {
        if (item.type() == typeid(int)) {
            vec.push_back(boost::any_cast<int>(item));
        } else {
            throw bad_any_cast();
        }
    }
}

int main() {
    std::vector<int> vec;
    std::list<boost::any> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back("string"); // This will trigger the bad_any_cast exception

    try {
        filter_integers(vec, lst);
    } catch (const bad_any_cast& e) {
        std::cerr << e.what() << std::endl;
    }

    for (const auto& v : vec) {
        std::cout << v << std::endl;
    }

    return 0;
}
```