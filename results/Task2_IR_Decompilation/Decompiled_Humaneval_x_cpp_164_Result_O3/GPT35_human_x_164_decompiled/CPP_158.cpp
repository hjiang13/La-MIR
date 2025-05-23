```c++
#include <string>
#include <vector>

void find_max(std::string& result, std::vector<std::string>& input) {
    std::string maxString;
    int maxCount = 0;

    for (auto& str : input) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'x') {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            maxString = str;
        }
    }

    result = maxString;
}

int main() {
    std::vector<std::string> input = {"string1", "xxstringxx", "xstringx"};
    std::string result;
    find_max(result, input);
    return 0;
}
```