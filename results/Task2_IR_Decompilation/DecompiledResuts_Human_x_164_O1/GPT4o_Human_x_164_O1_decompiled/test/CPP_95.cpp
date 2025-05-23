#include <map>
#include <string>
#include <cstring>

bool check_dict_case(std::map<std::string, std::string>& dict) {
    std::string str;
    char* buffer = nullptr;
    size_t length = 0;

    auto it = dict.begin();
    if (it == dict.end()) {
        return false;
    }

    do {
        if (buffer == nullptr) {
            length = 16; // Assuming some length for the example
            buffer = new char[length];
        }

        std::string key = it->first;
        if (key.length() > 15) {
            char* newBuffer = new char[key.length() + 1];
            memcpy(newBuffer, buffer, length);
            delete[] buffer;
            buffer = newBuffer;
            length = key.length() + 1;
        }

        strcpy(buffer, key.c_str());

        bool condition = false;
        for (size_t i = 0; i < strlen(buffer); ++i) {
            if (buffer[i] < 65) { // ASCII value for 'A'
                condition = true;
                break;
            }
        }

        if (!condition) {
            delete[] buffer;
            return true;
        }

        ++it;
    } while (it != dict.end());

    delete[] buffer;
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
