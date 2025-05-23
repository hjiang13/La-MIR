#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string>& dict) {
    if (dict.size() == 0) return false;

    auto it = dict.begin();
    auto end = dict.end();
    bool isValid = true;

    while (it != end) {
        char c = it->first[0];

        if (c < 'A' || c > 'z' || (c > 'Z' && c < 'a')) {
            isValid = false;
            break;
        }

        ++it;
    }

    return isValid;
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
