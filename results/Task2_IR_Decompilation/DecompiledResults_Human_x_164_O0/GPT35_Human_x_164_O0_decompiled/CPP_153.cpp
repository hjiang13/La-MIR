```c++
#include <string>
#include <vector>

void Strongest_Extension(std::string& result, std::string* input, std::vector<std::string>* vector) {
    std::string temp;
    temp.append("a");

    int index = -1000;
    int i = 0;
    while (i < vector->size()) {
        int j = 0;
        int length = input->length();
        std::string& str = vector->at(i);
        char c = str[j];
        if (c >= 65 && c <= 90) {
            if (str[j] >= 97 && str[j] <= 122) {
                index--;
            }
        }
        i++;
    }

    std::string temp_str;
    temp_str.append(input->at(index));
    result = temp_str;
}
```