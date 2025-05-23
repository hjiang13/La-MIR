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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (boost::any_cast<int>(compare_one(1, 2)) == 2);
    assert (boost::any_cast<double>(compare_one(1, 2.5))== 2.5);
    assert (boost::any_cast<int>(compare_one(2, 3)) == 3);
    assert (boost::any_cast<int>(compare_one(5, 6)) == 6);
    assert (boost::any_cast<string>(compare_one(1, string("2,3")))== "2,3");
    assert (boost::any_cast<string>(compare_one(string("5,1"), string("6"))) == "6");
    assert (boost::any_cast<string>(compare_one(string("1"), string("2"))) == "2");
    assert (boost::any_cast<string>(compare_one(string("1"), 1)) == "None");
}
