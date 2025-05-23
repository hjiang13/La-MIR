/*
Filter given vector of any python values only for integers
>>> filter_integers({"a", 3.14, 5})
{5}
>>> filter_integers({1, 2, 3, "abc", {}, {}})
{1, 2, 3}
*/
#include<stdio.h>
#include<vector>
#include<string>
#include<boost/any.hpp>
#include<list>
typedef std::list<boost::any> list_any;
using namespace std;
vector<int> filter_integers(list_any values){

    list_any::iterator it;
    boost::any anyone;
    vector<int> out;
    for (it=values.begin();it!=values.end();it++)
    {
         anyone=*it;
        if( anyone.type() == typeid(int) )
           out.push_back(boost::any_cast<int>(*it));
    }
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
    assert (issame(filter_integers({}),{}));

    assert (issame(filter_integers({4,  {},23.2, 9, string("adasd")}) ,{4, 9}));
    assert (issame(filter_integers({3, 'c', 3, 3, 'a', 'b'}) ,{3, 3, 3}));
}