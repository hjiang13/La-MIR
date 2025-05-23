#include <vector>
#include <string>
#include <cstring>
#include <iostream>

void reverse_delete(std::vector<std::string>& vec, const std::string& str1, const std::string& str2) {
    size_t size = vec.size();
    for (size_t i = 0; i < size; ++i) {
        if (vec[i] == str1 || vec[i] == str2) {
            vec.erase(vec.begin() + i);
            --i; // Adjust index after erase
            --size; // Update size
        }
    }
}

int main() {
    std::vector<std::string> vec = {"Hello", "World", "Foo", "Bar", "Baz"};
    std::string str1 = "Foo";
    std::string str2 = "Bar";
    reverse_delete(vec, str1, str2);
    
    for (const auto& str : vec) {
        std::cout << str << std::endl;
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
