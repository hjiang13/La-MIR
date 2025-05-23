#include <string>
#include <iostream>

bool correct_bracketing(std::basic_string<char> &str) {
    if (str.size() == 0)
        return true;

    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '<')
            count++;
        else if (str[i] == '>')
            count--;

        if (count < 0)
            return false;
    }

    return count == 0;
}

int main() {
    std::string input = "<><<>>";
    
    if (correct_bracketing(input))
        std::cout << "Bracketing is correct" << std::endl;
    else
        std::cout << "Bracketing is incorrect" << std::endl;

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (correct_bracketing("<>"));
    assert (correct_bracketing("<<><>>"));
    assert (correct_bracketing("<><><<><>><>"));
    assert (correct_bracketing("<><><<<><><>><>><<><><<>>>"));
    assert (not (correct_bracketing("<<<><>>>>")));
    assert (not (correct_bracketing("><<>")));
    assert (not (correct_bracketing("<")));
    assert (not (correct_bracketing("<<<<")));
    assert (not (correct_bracketing(">")));
    assert (not (correct_bracketing("<<>")));
    assert (not (correct_bracketing("<><><<><>><>><<>")));
    assert (not (correct_bracketing("<><><<><>><>>><>")));
}
