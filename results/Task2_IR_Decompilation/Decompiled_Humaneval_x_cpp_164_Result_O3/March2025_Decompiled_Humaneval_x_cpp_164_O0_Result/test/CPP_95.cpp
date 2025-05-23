#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string> &m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        const std::string &key = it->first;
        bool has_upper = false;
        bool has_lower = false;

        for (char c : key) {
            if (c >= 'A' && c <= 'Z') {
                has_upper = true;
            } else if (c >= 'a' && c <= 'z') {
                has_lower = true;
            }

            if (has_upper && has_lower) {
                return false;
            }
        }
    }
    return true;
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
