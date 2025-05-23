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
