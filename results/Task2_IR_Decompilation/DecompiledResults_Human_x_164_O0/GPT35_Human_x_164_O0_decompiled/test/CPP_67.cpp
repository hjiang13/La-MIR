#include <string>
#include <cstdlib>

int fruit_distribution(std::basic_string<char>* str, int num) {
    std::basic_string<char> str1 = "1";
    std::basic_string<char> str2 = "1";
    int var1 = 0;
    int var2 = 0;
    
    while (var2 < str->size()) {
        char ch = (*str)[var2];
        int val = static_cast<int>(ch);
        
        if (val >= 48 && val <= 57) {
            var1++;
            if (var1 == 1) {
                str1 += ch;
            } else {
                str2 += ch;
            }
        }
        var2++;
    }
    
    int result1 = std::stoi(str1) - std::stoi(str2);
    
    return result1;
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
