#include <string.h>

void string_xor(std::string* result, const std::string* str1, const std::string* str2) {
    result->_M_mutate(0, 0, nullptr, 0);
    result->size = 0;
    result->capacity = 0;

    if (str1->size == 0) {
        return;
    }

    for (size_t i = 0; i < str1->size; ++i) {
        if (i >= str2->size) {
            break;
        }

        char c1 = str1->data()[i];
        char c2 = str2->data()[i];

        if (c1 == c2) {
            if (result->size >= result->capacity) {
                result->_M_mutate(result->size, 0, nullptr, 1);
            }
            result->data()[result->size++] = 48;
        } else {
            if (result->size >= result->capacity) {
                result->_M_mutate(result->size, 0, nullptr, 1);
            }
            result->data()[result->size++] = 49;
        }
    }

    result->data()[result->size] = 0;
}
