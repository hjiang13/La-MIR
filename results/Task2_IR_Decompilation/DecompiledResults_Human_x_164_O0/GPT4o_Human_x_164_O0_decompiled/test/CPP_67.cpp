#include <string>
#include <cstdlib>

int fruit_distribution(std::string &input_string, int counter) {
    int index = 0;
    int length = 0;
    std::string temp_string;

    while (index < input_string.size()) {
        char current_char = input_string[index];

        if (current_char >= '0' && current_char <= '9') {
            break;
        }

        index++;
    }

    if (index < input_string.size()) {
        while (index < input_string.size()) {
            char current_char = input_string[index];

            if (current_char < '0' || current_char > '9') {
                if (length == 0) {
                    temp_string += current_char;
                }
            } else {
                break;
            }
            index++;
        }

        if (input_string.size() > 0) {
            length = 1;
        }

        while (index < input_string.size()) {
            char current_char = input_string[index];

            if (current_char >= '0' && current_char <= '9') {
                counter++;
            }

            index++;
        }
    }

    const char* input_c_str = input_string.c_str();
    int number_from_input = atoi(input_c_str);
    return counter - number_from_input;
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
