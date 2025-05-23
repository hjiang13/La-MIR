#include <string>
#include <cstdlib>

int fruit_distribution(const std::string& input, int number) {
    std::string str1;
    std::string str2;
    int result = 0;
    int flag = 0;

    for (int i = 0; i < input.size(); ++i) {
        char ch = input[i];
        if (ch >= '0' && ch <= '9') {
            if (flag == 0) {
                str1 += ch;
            } else if (flag == 1) {
                str2 += ch;
            }
        } else {
            if (flag == 0 && !str1.empty()) {
                flag = 1;
            }
        }
    }

    int num1 = std::atoi(str1.c_str());
    int num2 = std::atoi(str2.c_str());
    result = number - num1 - num2;

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
