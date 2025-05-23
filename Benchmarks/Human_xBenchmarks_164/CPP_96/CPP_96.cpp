/*
Implement a function that takes an non-negative integer and returns a vector of the first n
integers that are prime numbers and less than n.
for example:
count_up_to(5) => {2,3}
count_up_to(11) => {2,3,5,7}
count_up_to(0) => {}
count_up_to(20) => {2,3,5,7,11,13,17,19}
count_up_to(1) => {}
count_up_to(18) => {2,3,5,7,11,13,17}
*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<int> count_up_to(int n){

    vector<int> out={};
    int i,j;
    for (i=2;i<n;i++)
        if (out.size()==0) {out.push_back(i);}
        else
        {
            bool isp=true;
            for (j=0;out[j]*out[j]<=i;j++)
                if (i%out[j]==0) isp=false;
            if (isp) out.push_back(i);
        }
    return out;
}
