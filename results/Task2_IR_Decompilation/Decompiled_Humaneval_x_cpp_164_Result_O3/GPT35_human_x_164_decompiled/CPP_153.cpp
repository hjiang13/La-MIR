```cpp
#include <string>
#include <vector>

void Strongest_Extension(std::string &result, const std::string &input, const std::vector<std::string> &data) {
    std::__cxx11::basic_string<char> s;
    std::__cxx11::basic_string<char> temp;
    s = "";
    for (auto str : data) {
        temp = str;
        if (temp.size() == 0) {
            continue;
        }
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] < 'A' || temp[i] > 'Z') {
                temp[i] = temp[i] - 65;
            }
            else {
                temp[i] = temp[i] - 97;
            }
        }
        s += temp;
    }
    result = s;
}

int main() {
    std::string result;
    std::string input = "input_string";
    std::vector<std::string> data = {"data_1", "data_2", "data_3"};
    Strongest_Extension(result, input, data);
    return 0;
}
```