```cpp
#include <boost/any.hpp>
#include <boost/bad_any_cast.hpp>
#include <string>
#include <cstring>

void compare_one(boost::any& a, boost::any& b, boost::any& result) {
    boost::bad_any_cast bad_cast;
    if (a.empty()) {
        throw bad_cast;
    }

    const std::type_info& a_type = a.type();
    const std::type_info& b_type = b.type();

    if (a_type == typeid(std::string)) {
        std::string str_a = boost::any_cast<std::string>(a);
        std::string str_b = boost::any_cast<std::string>(b);
        result = str_a == str_b;
    } else {
        throw bad_cast;
    }
}

int main() {
    boost::any a = std::string("test");
    boost::any b = std::string("test");
    boost::any result;

    try {
        compare_one(a, b, result);
    } catch (const boost::bad_any_cast& e) {
        // Handle the exception
    }

    return 0;
}
```