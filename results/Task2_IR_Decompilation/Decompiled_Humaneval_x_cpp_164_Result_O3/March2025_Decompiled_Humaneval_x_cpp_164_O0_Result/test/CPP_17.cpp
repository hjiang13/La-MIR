#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

std::vector<int> parse_music(const std::string& input) {
    std::vector<int> result;
    std::string temp;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c == ' ') {
            if (temp == "o") {
                result.push_back(4);
            } else if (temp == "o|") {
                result.push_back(2);
            } else if (temp == ".|") {
                result.push_back(1);
            }
            temp.clear();
        } else {
            temp += c;
        }
    }
    return result;
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
