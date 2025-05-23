/*
Given a positive integer n, return a sorted vector that has the odd numbers in collatz sequence.

The Collatz conjecture is a conjecture in mathematics that concerns a sequence defined
as follows: start with any positive integer n. Then each term is obtained from the 
previous term as follows: if the previous term is even, the next term is one half of 
the previous term. If the previous term is odd, the next term is 3 times the previous
term plus 1. The conjecture is that no matter what value of n, the sequence will always reach 1.

Note: 
    1. Collatz(1) is {1}.
    2. returned vector sorted in increasing order.

For example:
get_odd_collatz(5) returns {1, 5} // The collatz sequence for 5 is {5, 16, 8, 4, 2, 1}, so the odd numbers are only 1, and 5.
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> get_odd_collatz(int n){

    vector<int> out={1};
    while (n!=1)
    {
        if (n%2==1) {out.push_back(n); n=n*3+1;}
        else n=n/2;
    }
    sort(out.begin(),out.end());
    return out;
}
