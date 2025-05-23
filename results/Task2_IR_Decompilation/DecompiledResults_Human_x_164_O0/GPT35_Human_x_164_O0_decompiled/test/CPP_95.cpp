```c
#include <iostream>
#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string>& dict) {
    bool result = false;
    std::map<std::string, std::string>::iterator it = dict.begin();
    int count = 0;

    for (; it != dict.end(); ++it) {
        std::string key = it->first;
        count = 0;

        for (int i = 0; i < key.length(); i++) {
            char ch = key[i];

            if (ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z') {
                result = false;
                count = 1;
                break;
            }
        }

        if (count == 0) {
            result = true;
            break;
        }
    }

    return result;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (check_dict_case({{"p","pineapple"}, {"b","banana"}}) == true);
    assert (check_dict_case({{"p","pineapple"}, {"A","banana"}, {"B","banana"}}) == false);
    assert (check_dict_case({{"p","pineapple"}, {"5","banana"}, {"a","apple"}}) == false);
    assert (check_dict_case({{"Name","John"}, {"Age","36"}, {"City","Houston"}}) == false);
    assert (check_dict_case({{"STATE","NC"}, {"ZIP","12345"} }) == true  );
    assert (check_dict_case({{"fruit","Orange"}, {"taste","Sweet"} }) == true  );
    assert (check_dict_case({}) == false);
}
