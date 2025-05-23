```c++
#include <string>
#include <cstring>

int how_many_times(std::__cxx11::basic_string<char>& str1, std::__cxx11::basic_string<char>& str2) {
    if (str1.size() == 0) {
        return 0;
    }

    if (str2.size() < str1.size()) {
        throw std::__cxx11::basic_string<char>::out_of_range("basic_string::substr");
    }

    char* temp = new char[str1.size()];
    std::memcpy(temp, str1.c_str(), str1.size());

    int count = 0;
    for (int i = 0; i <= str2.size() - str1.size(); ++i) {
        if (std::memcmp(temp, str2.c_str() + i, str1.size()) == 0) {
            count++;
        }
    }

    delete[] temp;
    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (how_many_times("", "x") == 0);
    assert (how_many_times("xyxyxyx", "x") == 4);
     assert (how_many_times("cacacacac", "cac") == 4);
    assert (how_many_times("john doe", "john") == 1);
}
