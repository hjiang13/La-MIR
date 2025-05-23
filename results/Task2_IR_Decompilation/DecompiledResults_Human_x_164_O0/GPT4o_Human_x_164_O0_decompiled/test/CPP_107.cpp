#include <iostream>
#include <vector>
#include <string>

void even_odd_palindrome(std::vector<int>& vec, int num) {
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 1; i <= num; ++i) {
        if (i % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    vec.push_back(oddCount);
    vec.push_back(evenCount);
}

int main() {
    std::vector<int> result;
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    even_odd_palindrome(result, number);

    std::cout << "Odd Count: " << result[0] << ", Even Count: " << result[1] << std::endl;

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
