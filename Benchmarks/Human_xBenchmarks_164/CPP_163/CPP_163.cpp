/*
Given two positive integers a and b, return the even digits between a
and b, in ascending order.

For example:
generate_integers(2, 8) => {2, 4, 6, 8}
generate_integers(8, 2) => {2, 4, 6, 8}
generate_integers(10, 14) => {}
*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> generate_integers(int a,int b){

    int m;
    if (b<a)
    {
        m=a;a=b;b=m;
    }

    vector<int> out={};
    for (int i=a;i<=b;i++)
    if (i<10 and i%2==0) out.push_back(i);
    return out;
}
