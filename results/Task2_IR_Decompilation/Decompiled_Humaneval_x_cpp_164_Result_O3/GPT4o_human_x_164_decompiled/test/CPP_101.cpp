#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

class MyVector {
public:
    std::vector<std::string> vec;

    void words_string(std::string str) {
        if (str.empty()) {
            return;
        }

        size_t len = str.size();
        if (len > 15) {
            vec.resize(len);
        }

        for (size_t i = 0; i < len; ++i) {
            if (i < vec.size()) {
                vec[i] = str[i];
            } else {
                vec.push_back(std::string(1, str[i]));
            }
        }
    }

    ~MyVector() {
        vec.clear();
    }
};

int main() {
    MyVector myVec;
    myVec.words_string("example string");
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
    assert (issame(words_string("Hi, my name is John") , {"Hi", "my", "name", "is", "John"}));
    assert (issame(words_string("One, two, three, four, five, six") , {"One", "two", "three", "four", "five", "six"}));
    assert (issame(words_string("Hi, my name") , {"Hi", "my", "name"}));
    assert (issame(words_string("One,, two, three, four, five, six,") , {"One", "two", "three", "four", "five", "six"}));
    assert (issame(words_string("") , {}));
    assert (issame(words_string("ahmed     , gamal") , {"ahmed", "gamal"}));
}
