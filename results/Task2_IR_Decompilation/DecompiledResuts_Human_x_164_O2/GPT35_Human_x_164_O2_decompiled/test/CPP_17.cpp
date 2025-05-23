```cpp
#include <vector>
#include <string>

void parse_music(std::vector<int>& vec, std::__cxx11::basic_string<char>& str) {
    std::__cxx11::basic_string<char> temp_str;
    
    if (str.size() == 0) {
        return;
    }
    
    for (char c : str) {
        temp_str.push_back(c);
    }
    
    vec.clear();
    
    for (int i = 0; i < temp_str.size(); i++) {
        vec.push_back(temp_str[i]);
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
