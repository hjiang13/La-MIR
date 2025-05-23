#include <vector>
#include <string>
#include <cstring>
#include <iostream>

void reverse_delete(std::vector<std::string> &vec, const std::string &str1, const std::string &str2) {
    size_t size1 = str1.size();
    size_t size2 = str2.size();
    vec.clear();
    vec.reserve(2);
    vec.emplace_back(str1);
    vec.emplace_back(str2);
    
    for (size_t i = 0; i < size1; ++i) {
        if (str1[i] == str2[0]) {
            vec.push_back(str1);
            break;
        }
    }

    if (size1 == 0 || size2 == 0) {
        return;
    }

    std::string temp;
    if (size1 > 15) {
        temp = str1;
        std::memcpy(&temp[0], &str1[0], size1);
    } else {
        temp = str1;
    }

    if (temp == str2) {
        return;
    }

    for (size_t i = 0; i < size1; ++i) {
        if (temp[i] != str2[i % size2]) {
            vec.push_back(temp);
            break;
        }
    }
    
    std::cout << "Final vector size: " << vec.size() << std::endl;
}

int main() {
    std::vector<std::string> vec;
    std::string str1 = "Hello";
    std::string str2 = "World";
    
    reverse_delete(vec, str1, str2);
    
    for (const auto &s : vec) {
        std::cout << s << std::endl;
    }
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(reverse_delete("abcde","ae") , {"bcd","False"}));
    assert (issame(reverse_delete("abcdef", "b") , {"acdef","False"}));
    assert (issame(reverse_delete("abcdedcba","ab") , {"cdedc","True"}));
    assert (issame(reverse_delete("dwik","w") , {"dik","False"}));
    assert (issame(reverse_delete("a","a") , {"","True"}));
    assert (issame(reverse_delete("abcdedcba","") , {"abcdedcba","True"}));
    assert (issame(reverse_delete("abcdedcba","v") , {"abcdedcba","True"}));
    assert (issame(reverse_delete("vabba","v") , {"abba","True"}));
    assert (issame(reverse_delete("mamma", "mia") , {"", "True"}));
}
