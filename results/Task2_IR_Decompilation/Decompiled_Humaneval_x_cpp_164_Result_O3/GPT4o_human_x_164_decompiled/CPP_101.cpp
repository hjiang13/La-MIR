```cpp
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

class MyVector {
public:
    std::vector<std::string> vec;

    void words_string(std::string str) {
        if (str.empty()) {
            return;
        }

        size_t len = str.size();
        if (len > 15) {
            vec.resize(len);
        }

        for (size_t i = 0; i < len; ++i) {
            if (i < vec.size()) {
                vec[i] = str[i];
            } else {
                vec.push_back(std::string(1, str[i]));
            }
        }
    }

    ~MyVector() {
        vec.clear();
    }
};

int main() {
    MyVector myVec;
    myVec.words_string("example string");
    return 0;
}
```