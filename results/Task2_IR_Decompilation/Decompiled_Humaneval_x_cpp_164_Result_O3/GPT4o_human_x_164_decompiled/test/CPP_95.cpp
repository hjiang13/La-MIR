#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string> &dictionary) {
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        const std::string &key = it->first;
        int count = 0;

        for (size_t i = 0; i < key.size(); ++i) {
            char c = key[i];
            if (c < 'A' || c > 'z') {
                continue;
            }
            if (c >= 'A' && c <= 'Z') {
                c += 32; // Convert to lowercase
            }
            if (c >= 'a' && c <= 'z') {
                if (++count > 2) {
                    return false;
                }
            }
        }

        if (count != 2) {
            return false;
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
