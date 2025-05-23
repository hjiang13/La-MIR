#include <string>
#include <cstdlib>

using namespace std;

int fruit_distribution(basic_string<char>* str, int num) {
    basic_string<char> str1;
    basic_string<char> str2;
    basic_string<char> str3;
    basic_string<char> str4;

    str1 = "";
    str2 = "";

    if (str->size() == 0) {
        return num;
    }

    char* ptr1 = &str1[0];
    char* ptr2 = &str2[0];
    char* ptr3 = &str->at(0);
    char* ptr4 = &str4[0];

    int val1 = strtol(ptr3, nullptr, 10);
    int val2 = strtol(ptr4, nullptr, 10);

    if (str->at(0) == '\0') {
        return num - (val1 + val2);
    }

    return num;
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
