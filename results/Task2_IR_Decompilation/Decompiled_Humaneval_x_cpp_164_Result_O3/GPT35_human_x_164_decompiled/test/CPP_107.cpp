#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

void even_odd_palindrome(std::vector<int>& result, int size) {
    if (size < 1) {
        return;
    }

    std::memset(result.data(), 0, 24);

    int* ptr1 = static_cast<int*>(std::malloc(8));
    *ptr1 = 0;
    int* ptr2 = ptr1 + 1;
    *ptr2 = 0;

    result.push_back(*ptr1);
    result.push_back(*ptr2);

    std::memcpy(result.data() + 4, ptr1, 4);

    std::free(ptr1);
}

int main() {
    std::vector<int> vec;
    even_odd_palindrome(vec, 10);

    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
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
