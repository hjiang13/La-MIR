#include <string>

int how_many_times(const std::string& str1, const std::string& str2) {
    if (str1.length() == 0) {
        return 0;
    }

    int count = 0;
    int i = 0;
    while (i <= str1.length() - str2.length()) {
        std::string substr = str1.substr(i, str2.length());
        if (substr == str2) {
            count++;
        }
        i++;
    }
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
