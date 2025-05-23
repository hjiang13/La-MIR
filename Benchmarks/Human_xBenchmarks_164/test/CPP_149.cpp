/*
Write a function that accepts a vector of strings as a parameter,
deletes the strings that have odd lengths from it,
and returns the resulted vector with a sorted order,
The vector is always a vector of strings and never a vector of numbers,
and it may contain duplicates.
The order of the vector should be ascending by length of each word, and you
should return the vector sorted by that rule.
If two words have the same length, sort the vector alphabetically.
The function should return a vector of strings in sorted order.
You may assume that all words will have the same length.
For example:
assert vector_sort({"aa", "a", "aaa"}) => {"aa"}
assert vector_sort({"ab", "a", "aaa", "cd"}) => {"ab", "cd"}
*/
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> sorted_list_sum(vector<string> lst){

    vector<string> out={};
    for (int i=0;i<lst.size();i++)
    if (lst[i].length()%2==0) out.push_back(lst[i]);
    string mid;
    sort(out.begin(),out.end());
    for (int i=0;i<out.size();i++)
    for (int j=1;j<out.size();j++)
    if (out[j].length()<out[j-1].length())
    {
        mid=out[j];out[j]=out[j-1];out[j-1]=mid;
    }
    return out;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(sorted_list_sum({"aa", "a", "aaa"}) , {"aa"}));
    assert (issame(sorted_list_sum({"school", "AI", "asdf", "b"}) , {"AI", "asdf", "school"}));
    assert (issame(sorted_list_sum({"d", "b", "c", "a"}) , {}));
    assert (issame(sorted_list_sum({"d", "dcba", "abcd", "a"}) , {"abcd", "dcba"}));
    assert (issame(sorted_list_sum({"AI", "ai", "au"}) , {"AI", "ai", "au"}));
    assert (issame(sorted_list_sum({"a", "b", "b", "c", "c", "a"}) , {}));
    assert (issame(sorted_list_sum({"aaaa", "bbbb", "dd", "cc"}) , {"cc", "dd", "aaaa", "bbbb"}));
}
