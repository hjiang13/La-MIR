```cpp
#include <vector>
#include <list>
#include <boost/any.hpp>
#include <typeinfo>

std::vector<int> filter_integers(std::list<boost::any> input_list) {
    std::vector<int> result;
    for (auto it = input_list.begin(); it != input_list.end(); ++it) {
        boost::any& any_value = *it;
        if (any_value.type() == typeid(int)) {
            int value = boost::any_cast<int>(any_value);
            result.push_back(value);
        }
    }
    return result;
}
```