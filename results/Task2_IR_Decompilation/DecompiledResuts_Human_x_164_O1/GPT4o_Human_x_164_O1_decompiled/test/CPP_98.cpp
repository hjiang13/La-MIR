#include <string>

int count_upper(const std::string& str) {
    int count = 0;
    size_t length = str.length();
    
    if (length == 0) {
        return count;
    }

    for (size_t i = 0; i < length; ++i) {
        if (isupper(str[i])) {
            count++;
        }
    }
    
    return count;
}

int main() {
    std::string testString = "AEIOU";
    int upperCount = count_upper(testString);
    return upperCount;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_upper("aBCdEf")  == 1);
    assert (count_upper("abcdefg") == 0);
    assert (count_upper("dBBE") == 0);
    assert (count_upper("B")  == 0);
    assert (count_upper("U")  == 1);
    assert (count_upper("") == 0);
    assert (count_upper("EEEE") == 2);
}
