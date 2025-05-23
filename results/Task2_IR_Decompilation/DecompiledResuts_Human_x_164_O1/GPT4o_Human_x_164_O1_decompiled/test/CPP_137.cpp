#include <boost/any.hpp>
#include <boost/exception/all.hpp>
#include <cstring>
#include <string>
#include <stdexcept>

namespace boost {
    class bad_any_cast : public std::bad_cast {
    public:
        const char* what() const noexcept override {
            return "boost::bad_any_cast: failed conversion using boost::any_cast";
        }
    };

    namespace exception_detail {
        struct error_info_injector {
            bad_any_cast* what;
            error_info_injector() : what(nullptr) {}
            ~error_info_injector() { delete what; }
        };
    }

    template<typename T>
    T any_cast(const any& operand) {
        if (operand.type() != typeid(T)) {
            throw bad_any_cast();
        }
        return *static_cast<const T*>(operand.get());
    }

    void compare_one(any& a, any& b) {
        if (a.empty() || b.empty()) {
            throw bad_any_cast();
        }
        const std::string& str_a = any_cast<std::string>(a);
        const std::string& str_b = any_cast<std::string>(b);
        if (str_a != str_b) {
            throw bad_any_cast();
        }
    }
}

extern "C" double strtod(const char* str, char** endptr);

extern "C" void my_function(boost::any& a, boost::any& b) {
    try {
        boost::exception_detail::error_info_injector info;
        boost::compare_one(a, b);
    } catch (const boost::bad_any_cast& e) {
        throw;
    }
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
