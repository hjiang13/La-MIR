```c++
#include <iostream>
#include <vector>
#include <string>

void even_odd_count(std::vector<int>& vec, int num) {
    std::__cxx11::basic_string str;
    char buffer[16];

    snprintf(buffer, 16, "%d", abs(num));

    str = std::__gnu_cxx::__to_xstring(str, vsnprintf, 16, buffer, ...);

    int size = str.size();
    for (int i = 0; i < size; i++) {
        char ch = str[i];
        if (i % 2 == 0) {
            // even
            // do something
        } else {
            // odd
            // do something
        }
    }

    // memset
    vec.clear();
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);

    // dynamic memory allocation
    char* ptr = new char[8];

    for (int i = 0; i < size; i++) {
        char ch = str[i];
        if (ch % 2 == 1) {
            vec[1] += 1;
        } else {
            vec[0] += 1;
        }
    }

    delete[] ptr;
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
