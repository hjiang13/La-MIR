#include <vector>
#include <string>
#include <cstdlib>
#include <initializer_list>
#include <stdexcept>

std::vector<int> even_odd_count(int n) {
    std::string str = std::to_string(std::abs(n));
    int even_count = 0;
    int odd_count = 0;
    int index = 0;

    while (index < str.length()) {
        char c = str[index];
        int digit = static_cast<int>(c);
        if (digit % 2 == 1) {
            odd_count++;
        } else {
            even_count++;
        }
        index++;
    }

    std::initializer_list<int> init_list = {even_count, odd_count};
    std::vector<int> result(init_list);
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
    assert (issame(even_odd_count(7) , {0, 1}));
    assert (issame(even_odd_count(-78) , {1, 1}));
    assert (issame(even_odd_count(3452) , {2, 2}));
    assert (issame(even_odd_count(346211) , {3, 3}));
    assert (issame(even_odd_count(-345821) , {3, 3}));
    assert (issame(even_odd_count(-2) , {1, 0}));
    assert (issame(even_odd_count(-45347) , {2, 3}));
    assert (issame(even_odd_count(0) , {1, 0}));
}
