#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longest(std::string* result, std::vector<std::string>* vec) {
    result->assign("");
    if (vec->begin() == vec->end()) {
        return;
    }

    std::string* longest_str = &*vec->begin();
    int max_len = 0;
    for (auto it = vec->begin(); it != vec->end(); ++it) {
        if (it->length() > max_len) {
            longest_str = &*it;
            max_len = it->length();
        }
    }
    result->assign(*longest_str);
}
