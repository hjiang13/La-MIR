#include <vector>
#include <string>
#include <cstdio>
#include <cstdarg>

void even_odd_palindrome(std::vector<int>& result, int n) {
    if (n < 1) {
        result.clear();
        result.push_back(0);
        result.push_back(0);
        result.push_back(0);
        return;
    }

    result.clear();
    result.push_back(n);
    result.push_back(0);
    result.push_back(0);
}

int main() {
    std::vector<int> vec;
    int num = 10;

    even_odd_palindrome(vec, num);

    for (int i = 0; i < vec.size(); i++) {
        printf("%d\n", vec[i]);
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
    assert (issame(even_odd_palindrome(123) , {8, 13}));
    assert (issame(even_odd_palindrome(12) , {4, 6}));
    assert (issame(even_odd_palindrome(3) , {1, 2}));
    assert (issame(even_odd_palindrome(63) , {6, 8}));
    assert (issame(even_odd_palindrome(25) , {5, 6}));
    assert (issame(even_odd_palindrome(19) , {4, 6}));
    assert (issame(even_odd_palindrome(9) , {4, 5}));
    assert (issame(even_odd_palindrome(1) , {0, 1}));
}
