```c++
#include <string>

void string_xor(std::__cxx11::basic_string<char>* s1, std::__cxx11::basic_string<char>* s2, std::__cxx11::basic_string<char>* s3) {
    s1->clear();
    for (size_t i = 0; i < s2->size() && i < s3->size(); ++i) {
        char xor_result = s2->at(i) ^ s3->at(i);
        s1->push_back(xor_result);
    }
}

int main() {
    std::__cxx11::basic_string<char> str1 = "hello";
    std::__cxx11::basic_string<char> str2 = "world";
    std::__cxx11::basic_string<char> result;

    string_xor(&result, &str1, &str2);

    // Print the result
    for (char c : result) {
        std::cout << c;
    }

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (string_xor("111000", "101010") == "010010");
     assert (string_xor("1", "1") == "0");
    assert (string_xor("0101", "0000") == "0101");

}
