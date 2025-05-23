/*
From a vector of integers, remove all elements that occur more than once.
Keep order of elements left the same as in the input.
>>> remove_duplicates({1, 2, 3, 2, 4})
{1, 3, 4}
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> remove_duplicates(vector<int> numbers){

    vector<int> out={};
    vector<int> has1={};
    vector<int> has2={};
    for (int i=0;i<numbers.size();i++)
    {
        if (find(has2.begin(),has2.end(),numbers[i])!=has2.end()) continue;
        if (find(has1.begin(),has1.end(),numbers[i])!=has1.end())
        {

            has2.push_back(numbers[i]);
        }
        else has1.push_back(numbers[i]);
    }
    for (int i=0;i<numbers.size();i++)
    if (find(has2.begin(),has2.end(),numbers[i])==has2.end())
        out.push_back(numbers[i]);
    return out;


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
    assert (issame(remove_duplicates({}) , {}));
     assert (issame(remove_duplicates({1, 2, 3, 4}) , {1, 2, 3, 4}));
      assert (issame(remove_duplicates({1, 2, 3, 2, 4, 3, 5}) , {1, 4, 5}));
}
