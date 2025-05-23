#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void parse_music(std::vector<std::string>& vec, const std::string& input) {
    std::string temp;
    if (input.empty()) {
        return;
    }

    size_t length = input.size();
    if (length > 15) {
        temp.resize(length);
        std::memcpy(&temp[0], input.c_str(), length);
    } else {
        if (length == 1) {
            temp.resize(1);
            temp[0] = input[0];
        } else {
            temp.resize(length);
            std::memcpy(&temp[0], input.c_str(), length);
        }
    }

    vec.push_back(temp);
    vec.back().push_back('\0');
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(parse_music("") , {}));
     assert (issame(parse_music("o o o o") ,{4, 4, 4, 4}));
      assert (issame(parse_music(".| .| .| .|") , {1, 1, 1, 1}));
 assert (issame(parse_music("o| o| .| .| o o o o") , {2, 2, 1, 1, 4, 4, 4, 4}));
  assert (issame(parse_music("o| .| o| .| o o| o o|") , {2, 1, 2, 1, 4, 2, 4, 2}));
}
