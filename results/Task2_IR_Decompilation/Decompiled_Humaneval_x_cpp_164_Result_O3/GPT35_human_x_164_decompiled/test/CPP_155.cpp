#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void even_odd_count(std::vector<int>& result, int num) {
    std::__cxx11::basic_string<char> str;
    char buffer[16];
    int abs_num = std::abs(num);

    snprintf(buffer, 16, "%d", abs_num);
    str = buffer;

    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    result.push_back(even_count);
    result.push_back(odd_count);
}

int main() {
    std::vector<int> result;
    int num = 155;

    even_odd_count(result, num);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }

    return 0;
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
