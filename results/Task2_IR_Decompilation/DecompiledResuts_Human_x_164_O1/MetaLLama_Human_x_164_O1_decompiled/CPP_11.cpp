#include <string.h>

void string_xor(std::string* result, const std::string* str1, const std::string* str2) {
    result->clear();
    size_t len1 = str1->length();
    size_t len2 = str2->length();
    size_t min_len = (len1 < len2) ? len1 : len2;

    for (size_t i = 0; i < min_len; i++) {
        if (str1->at(i) == str2->at(i)) {
            result->push_back('0');
        } else {
            result->push_back('1');
        }
    }

    if (len1 > min_len) {
        for (size_t i = min_len; i < len1; i++) {
            result->push_back(str1->at(i));
        }
    } else if (len2 > min_len) {
        for (size_t i = min_len; i < len2; i++) {
            result->push_back(str2->at(i));
        }
    }
}
