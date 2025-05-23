#include <string>
#include <cstring>

int how_many_times(const std::string& str1, const std::string& str2) {
    int count1 = 0;
    int count2 = 0;

    if (str1.length() == 0) {
        return 0;
    }

    while (count1 < str1.length()) {
        size_t length2 = str2.length();
        size_t start = count1;

        if (count1 >= str1.length()) {
            break;
        }

        std::string substr = str1.substr(start, length2);
        if (substr == str2) {
            count1 += length2;
            count2++;
        } else {
            break;
        }
    }

    return count2;
}

int compare(const std::string &str1, const std::string &str2) {
    if (str1.size() == str2.size()) {
        return std::memcmp(str1.data(), str2.data(), str1.size());
    }
    return str1.size() < str2.size() ? -1 : 1;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (how_many_times("", "x") == 0);
    assert (how_many_times("xyxyxyx", "x") == 4);
     assert (how_many_times("cacacacac", "cac") == 4);
    assert (how_many_times("john doe", "john") == 1);
}
