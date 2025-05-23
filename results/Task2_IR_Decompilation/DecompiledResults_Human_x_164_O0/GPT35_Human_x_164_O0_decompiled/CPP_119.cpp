```c++
#include <iostream>
#include <string>
#include <vector>

void match_parens(std::string& result, std::vector<std::string>& input) {
    std::string str1 = input[0];
    std::string str2 = input[1];
    
    result = str1 + str2;
    
    int count = 0;
    bool flag = true;
    
    int index = 0;
    while(index < result.length()) {
        char c = result[index];
        
        if(c == '(') {
            count++;
        } else if(c == ')') {
            count--;
        }
        
        if(count < 0) {
            flag = false;
            break;
        }
        
        index++;
    }
    
    if(flag && count == 0) {
        result = "Yes";
    } else {
        result = "No";
    }
}

int main() {
    std::vector<std::string> input = {"Hello", "World"};
    std::string result;
    
    match_parens(result, input);
    
    std::cout << result << std::endl;
    
    return 0;
}
```