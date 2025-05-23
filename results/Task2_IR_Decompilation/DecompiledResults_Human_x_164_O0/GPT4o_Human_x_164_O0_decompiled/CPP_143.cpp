```cpp
#include <string>

struct Result {
    char* address;
    int code;
};

extern "C" Result words_in_sentence(std::string& str1, const std::string& str2) {
    std::string temp;
    std::string result;
    int count = 0;
    bool valid = false;

    while (true) {
        if (str1.size() > 0) {
            str1.pop_back();
            valid = true;
        } else {
            break;
        }

        if (valid) {
            for (size_t i = 0; i < str1.size(); ++i) {
                if (str1[i] != ' ') {
                    temp += str1[i];
                    count++;
                } else {
                    if (count > 0) {
                        result += temp + " ";
                        temp.clear();
                        count = 0;
                    }
                }
            }
            if (count > 0) {
                result += temp;
            }
        }
    }

    str1 = result;
    return {nullptr, 0};
}
```