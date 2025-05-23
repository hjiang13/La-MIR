```cpp
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

void even_odd_count(std::vector<int>& result, int input) {
    std::__cxx11::basic_string<char> temp;
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%d", abs(input));

    int even_count = 0;
    int odd_count = 0;
    for (size_t i = 0; i < temp.size(); ++i) {
        int num = buffer[i] - '0';
        if (num % 2 == 0) {
            ++even_count;
        } else {
            ++odd_count;
        }
    }

    result.push_back(even_count);
    result.push_back(odd_count);
}

int main() {
    std::vector<int> result;
    int input = 12345;
    even_odd_count(result, input);

    for (int i : result) {
        printf("%d\n", i);
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
