#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <cmath>

void even_odd_count(std::vector<int>& vec, int n) {
    std::string str;
    int even_count = 0;
    int odd_count = 0;
    int i = 0;

    int abs_val = std::abs(n);
    str = std::to_string(abs_val);

    while (i < str.length()) {
        char ch = str[i];
        if (ch % 2 == 1) {
            odd_count++;
        } else {
            even_count++;
        }
        i++;
    }

    vec = {even_count, odd_count};
}

int main() {
    std::vector<int> counts;
    even_odd_count(counts, -1234);
    std::cout << "Even count: " << counts[0] << ", Odd count: " << counts[1] << std::endl;
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
