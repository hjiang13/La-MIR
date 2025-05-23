```cpp
#include <map>
#include <string>

bool check_dict_case(std::map<std::string, std::string> *dict) {
    if (dict->empty()) {
        return true;
    }

    auto it = dict->begin();
    auto node = it->second;
    std::string str;
    str.reserve(node.size());

    for (auto c : node) {
        if (c < 'A' || c > 'Z') {
            return true;
        }

        str.push_back(c - 'A' + 'a');
    }

    dict->begin()->second = str;

    return false;
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
