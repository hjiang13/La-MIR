```c
#include <iostream>
#include <string>

void file_name_check(std::string& result, std::string* input) {
    if (input->length() < 5) {
        result = "No";
    } else {
        char firstChar = input->at(0);
        if ((firstChar < 'A' || firstChar > 'Z') && (firstChar < 'a' || firstChar > 'z')) {
            result = "No";
        } else {
            std::string ext = input->substr(input->length() - 4, 4);
            if (ext != ".txt" && ext != ".exe" && ext != ".dll") {
                result = "No";
            } else {
                result = "Yes";
            }
        }
    }
}

int main() {
    std::string input = "example.txt";
    std::string result;
    file_name_check(result, &input);
    std::cout << result << std::endl;
    return 0;
}
```