#include <string>
#include <cstdlib>

int fruit_distribution(const std::string& input, int value) {
    long num1 = 0, num2 = 0;
    std::string temp1, temp2;
    
    if (input.empty()) {
        return value;
    }

    const char* str1 = input.c_str();
    num1 = strtol(str1, nullptr, 10);
    
    const char* str2 = input.c_str();
    num2 = strtol(str2, nullptr, 10);
    
    int sum = static_cast<int>(num1) + static_cast<int>(num2);
    int result = value - sum;
    
    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (fruit_distribution("5 apples and 6 oranges",19) == 8);
    assert (fruit_distribution("5 apples and 6 oranges",21) == 10);
    assert (fruit_distribution("0 apples and 1 oranges",3) == 2);
    assert (fruit_distribution("1 apples and 0 oranges",3) == 2);
    assert (fruit_distribution("2 apples and 3 oranges",100) == 95);
    assert (fruit_distribution("2 apples and 3 oranges",5) == 0);
    assert (fruit_distribution("1 apples and 100 oranges",120) == 19);
}
