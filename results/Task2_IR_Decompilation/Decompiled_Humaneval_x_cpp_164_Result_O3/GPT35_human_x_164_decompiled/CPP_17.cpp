```c
#include <vector>
#include <string>

void parse_music(std::vector<int>& result, std::string& input) {
    std::__cxx11::basic_string<char> temp1;
    std::__cxx11::basic_string<char> temp2;

    temp1 = input;

    if (temp1.size() == 0) {
        return;
    }

    temp2 = temp1;

    for (int i = 0; i < temp1.size(); i++) {
        result.push_back(temp1[i]);
    }
}
```