```cpp
#include <vector>
#include <string>

void parse_music(std::vector<int>& result, std::string& input) {
    std::__cxx11::basic_string<char> temp;
    std::__cxx11::basic_string<char> temp2;

    temp = input;

    if (temp.size() == 0) {
        return;
    }

    temp2 = temp;

    if (temp.size() > 15) {
        temp2.clear();
        temp2 = temp.substr(0, 15);
    } else {
        if (temp.compare("\0") == 0) {
            return;
        }

        int size = 4;
        result.resize(size);
        std::copy(temp.begin(), temp.begin() + size, result.begin());
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
