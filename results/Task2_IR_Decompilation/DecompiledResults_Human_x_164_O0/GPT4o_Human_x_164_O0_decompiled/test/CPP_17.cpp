#include <vector>
#include <string>
#include <stdexcept>

void parse_music(std::vector<int>& vec, const std::string& str) {
    std::string temp;
    vec.clear();

    if (!str.empty()) {
        if (str == "o") {
            vec.push_back(4);
        } else if (str == "o|") {
            vec.push_back(2);
        } else if (str == ".|") {
            vec.push_back(1);
        } else {
            vec.push_back(0);
        }
    }
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
