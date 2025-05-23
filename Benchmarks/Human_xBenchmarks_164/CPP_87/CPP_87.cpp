/*
You are given a 2 dimensional data, as a nested vectors,
which is similar to matrix, however, unlike matrices,
each row may contain a different number of columns.
Given lst, and integer x, find integers x in the vector,
and return vector of vectors, {{x1, y1}, {x2, y2} ...} such that
each vector is a coordinate - {row, columns}, starting with 0.
Sort coordinates initially by rows in ascending order.
Also, sort coordinates of the row by columns in descending order.

Examples:
get_row({
  {1,2,3,4,5,6},
  {1,2,3,4,1,6},
  {1,2,3,4,5,1}
}, 1) == {{0, 0}, {1, 4}, {1, 0}, {2, 5}, {2, 0}}
get_row({}, 1) == {}
get_row({{}, {1}, {1, 2, 3}}, 3) == {{2, 2}}
*/
#include<stdio.h>
#include<vector>
using namespace std;
vector<vector<int>> get_row(vector<vector<int>> lst, int x){

    vector<vector<int>> out={};
    for (int i=0;i<lst.size();i++)
    for (int j=lst[i].size()-1;j>=0;j-=1)
    if (lst[i][j]==x) out.push_back({i,j});
    return out;
}
