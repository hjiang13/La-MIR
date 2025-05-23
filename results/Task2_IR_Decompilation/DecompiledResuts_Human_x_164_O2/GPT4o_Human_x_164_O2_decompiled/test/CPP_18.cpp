#include <string>
#include <stdexcept>
#include <cstring>

int how_many_times(const std::string& str1, const std::string& str2) {
    if (str1.size() == 0) return 0;
    if (str2.size() == 0) throw std::out_of_range("basic_string::substr: __pos is out of range");

    size_t count = 0;
    size_t pos = 0;

    while (true) {
        size_t found = str1.find(str2, pos);
        if (found == std::string::npos) break;
        count++;
        pos = found + str2.size();
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
