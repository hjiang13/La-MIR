/*
Write a function that accepts two vectors of strings and returns the vector that has 
total number of chars in the all strings of the vector less than the other vector.

if the two vectors have the same number of chars, return the first vector.

Examples
total_match({}, {}) ➞ {}
total_match({"hi", "admin"}, {"hI", "Hi"}) ➞ {"hI", "Hi"}
total_match({"hi", "admin"}, {"hi", "hi", "admin", "project"}) ➞ {"hi", "admin"}
total_match({"hi", "admin"}, {"hI", "hi", "hi"}) ➞ {"hI", "hi", "hi"}
total_match({"4"}, {"1", "2", "3", "4", "5"}) ➞ {"4"}
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
vector<string> total_match(vector<string> lst1,vector<string> lst2){

    int num1,num2,i;
    num1=0;num2=0;
    for (i=0;i<lst1.size();i++)
        num1+=lst1[i].length();
    for (i=0;i<lst2.size();i++)
        num2+=lst2[i].length();
    if (num1>num2) return lst2;
    return lst1;
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
    assert (issame(total_match({}, {}) , {}));
    assert (issame(total_match({"hi", "admin"}, {"hi", "hi"}) , {"hi", "hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hi", "hi", "admin", "project"}) , {"hi", "admin"}));
    assert (issame(total_match({"4"}, {"1", "2", "3", "4", "5"}) , {"4"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "Hi"}) , {"hI", "Hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "hi", "hi"}) , {"hI", "hi", "hi"}));
    assert (issame(total_match({"hi", "admin"}, {"hI", "hi", "hii"}) , {"hi", "admin"}));
    assert (issame(total_match({}, {"this"}) , {}));
    assert (issame(total_match({"this"}, {}) , {}));
}
