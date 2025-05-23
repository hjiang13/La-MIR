```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

void get_odd_collatzi(std::vector<int>& result, int input) {
    result.clear();
    result.reserve(3);

    if (input == 1) {
        result.push_back(1);
    } else {
        int remainder = input % 2;
        int quotient = input / 2;

        if (remainder == 1) {
            result.push_back(input);
        } else {
            if (quotient == 0) {
                throw std::length_error("vector::_M_realloc_insert");
            }

            int newSize = quotient + quotient / 2;
            newSize = std::min(std::max(newSize, 1), 2305843009213693951);

            std::vector<int> temp(newSize, 0);
            temp[0] = input;

            if (quotient > 0) {
                std::copy(result.begin(), result.end(), temp.begin() + 1);
            }

            result = temp;
        }
    }
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
    assert (issame(get_odd_collatz(14) , {1, 5, 7, 11, 13, 17}));
    assert (issame(get_odd_collatz(5) , {1, 5}));
    assert (issame(get_odd_collatz(12) , {1, 3, 5}));
    assert (issame(get_odd_collatz(1) , {1}));
}
