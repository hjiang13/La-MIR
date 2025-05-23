#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

void even_odd_count(std::vector<int>& vec, int num) {
    std::string result;
    int even_count = 0;
    int odd_count = 0;

    num = abs(num);
    snprintf(&result[0], result.size(), "%d", num);
    
    for (size_t i = 0; i < vec.size(); ++i) {
        int value = vec[i];
        if (value % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    result += " Even: ";
    result += std::to_string(even_count);
    result += " Odd: ";
    result += std::to_string(odd_count);
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    even_odd_count(vec, -5);
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
