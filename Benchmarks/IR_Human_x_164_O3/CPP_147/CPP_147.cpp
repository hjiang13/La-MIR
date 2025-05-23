/*
You are given a positive integer n. You have to create an integer vector a of length n.
    For each i (1 ≤ i ≤ n), the value of a{i} = i * i - i + 1.
    Return the number of triples (a{i}, a{j}, a{k}) of a where i < j < k, 
and a[i] + a[j] + a[k] is a multiple of 3.

Example :
    Input: n = 5
    Output: 1
    Explanation: 
    a = {1, 3, 7, 13, 21}
    The only valid triple is (1, 7, 13).
*/
#include<stdio.h>
#include<vector>
using namespace std;
int get_matrix_triples(int n){

    vector<int> a;
    vector<vector<int>> sum={{0,0,0}};
    vector<vector<int>> sum2={{0,0,0}};
    for (int i=1;i<=n;i++)
    {
        a.push_back((i*i-i+1)%3);
        sum.push_back(sum[sum.size()-1]);
        sum[i][a[i-1]]+=1;
    }
    for (int times=1;times<3;times++)
    {
    for (int i=1;i<=n;i++)
    {
        sum2.push_back(sum2[sum2.size()-1]);
        if (i>=1)
        for (int j=0;j<=2;j++)
            sum2[i][(a[i-1]+j)%3]+=sum[i-1][j];
    }
    sum=sum2;
    sum2={{0,0,0}};
    }

    return sum[n][0];
}
