#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>

void even_odd_palindrome(std::vector<std::string>& result, int n) {
    if (n < 1) {
        result.resize(2);
        result[0] = "";
        result[1] = "";
        return;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        std::string str = "string" + std::to_string(i);
        bool is_palindrome = true;
        int len = str.length();
        for (int j = 0; j < len / 2; ++j) {
            if (str[j] != str[len - j - 1]) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            count++;
        }
    }

    result.resize(2);
    result[0] = "Count of palindromes: " + std::to_string(count);
    result[1] = "Count of non-palindromes: " + std::to_string(n - count);
}

int main() {
    std::vector<std::string> result;
    even_odd_palindrome(result, 10);
    for (const auto& s : result) {
        std::cout << s << std::endl;
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
