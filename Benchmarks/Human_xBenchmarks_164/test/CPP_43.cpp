/*
pairs_sum_to_zero takes a vector of integers as an input.
it returns true if there are two distinct elements in the vector that
sum to zero, and false otherwise.
>>> pairs_sum_to_zero({1, 3, 5, 0})
false
>>> pairs_sum_to_zero({1, 3, -2, 1})
false
>>> pairs_sum_to_zero({1, 2, 3, 7})
false
>>> pairs_sum_to_zero({2, 4, -5, 3, 5, 7})
true
>>> pairs_sum_to_zero({1})
false
*/
#include<stdio.h>
#include<vector>
using namespace std;
bool pairs_sum_to_zero(vector<int> l){

    for (int i=0;i<l.size();i++)
    for (int j=i+1;j<l.size();j++)
    if (l[i]+l[j]==0) return true;
    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (pairs_sum_to_zero({1, 3, 5, 0}) == false);
    assert (pairs_sum_to_zero({1, 3, -2, 1}) == false);
    assert (pairs_sum_to_zero({1, 2, 3, 7}) == false);
    assert (pairs_sum_to_zero({2, 4, -5, 3, 5, 7}) == true);
    assert (pairs_sum_to_zero({1}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 30}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 31}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 30}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 31}) == false);
}
