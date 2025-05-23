#include <string>
#include <cstdlib>

int fruit_distribution(std::string input, int size) {
    long long_value1 = 0;
    long long_value2 = 0;
    std::string str1, str2;
    int result = size;

    if (input.size() == 0) {
        return result;
    }

    char* endptr1;
    long_value1 = strtol(input.c_str(), &endptr1, 10);

    char* endptr2;
    long_value2 = strtol(input.c_str(), &endptr2, 10);

    if (endptr1 == input.c_str() || endptr2 == input.c_str()) {
        return result;
    }

    result -= (static_cast<int>(long_value1) + static_cast<int>(long_value2));

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
