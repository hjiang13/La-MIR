#include <boost/any.hpp>
#include <boost/exception/all.hpp>
#include <boost/type_index.hpp>
#include <string>
#include <exception>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

using namespace std;
using namespace boost;

boost::any compare_one(boost::any a, boost::any b) {
    boost::any result;
    try {
        if (a.type() == typeid(std::string)) {
            std::string str_a = any_cast<std::string>(a);
            size_t pos = str_a.find(',');
            if (pos != std::string::npos) {
                str_a = str_a.substr(0, pos) + '.' + str_a.substr(pos + 1);
            }
            double val_a = atof(str_a.c_str());
            if (b.type() == typeid(std::string)) {
                std::string str_b = any_cast<std::string>(b);
                pos = str_b.find(',');
                if (pos != std::string::npos) {
                    str_b = str_b.substr(0, pos) + '.' + str_b.substr(pos + 1);
                }
                double val_b = atof(str_b.c_str());
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else if (b.type() == typeid(int)) {
                int int_b = any_cast<int>(b);
                double val_b = static_cast<double>(int_b);
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else if (b.type() == typeid(double)) {
                double val_b = any_cast<double>(b);
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else {
                throw bad_any_cast();
            }
        } else if (a.type() == typeid(int)) {
            int int_a = any_cast<int>(a);
            double val_a = static_cast<double>(int_a);
            if (b.type() == typeid(std::string)) {
                std::string str_b = any_cast<std::string>(b);
                size_t pos = str_b.find(',');
                if (pos != std::string::npos) {
                    str_b = str_b.substr(0, pos) + '.' + str_b.substr(pos + 1);
                }
                double val_b = atof(str_b.c_str());
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else if (b.type() == typeid(int)) {
                int int_b = any_cast<int>(b);
                double val_b = static_cast<double>(int_b);
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else if (b.type() == typeid(double)) {
                double val_b = any_cast<double>(b);
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else {
                throw bad_any_cast();
            }
        } else if (a.type() == typeid(double)) {
            double val_a = any_cast<double>(a);
            if (b.type() == typeid(std::string)) {
                std::string str_b = any_cast<std::string>(b);
                size_t pos = str_b.find(',');
                if (pos != std::string::npos) {
                    str_b = str_b.substr(0, pos) + '.' + str_b.substr(pos + 1);
                }
                double val_b = atof(str_b.c_str());
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else if (b.type() == typeid(int)) {
                int int_b = any_cast<int>(b);
                double val_b = static_cast<double>(int_b);
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else if (b.type() == typeid(double)) {
                double val_b = any_cast<double>(b);
                if (val_a == val_b) {
                    result = std::string("None");
                } else if (val_a < val_b) {
                    result = b;
                } else if (val_a > val_b) {
                    result = a;
                } else {
                    throw std::runtime_error("Unexpected comparison result");
                }
            } else {
                throw bad_any_cast();
            }
        } else {
            throw bad_any_cast();
        }
    } catch (const bad_any_cast& e) {
        throw;
    }
    return result;
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
