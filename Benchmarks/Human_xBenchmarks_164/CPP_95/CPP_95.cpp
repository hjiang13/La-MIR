/*
Given a map, return true if all keys are strings in lower 
case or all keys are strings in upper case, else return false.
The function should return false is the given map is empty.
Examples:
check_map_case({{"a","apple"}, {"b","banana"}}) should return true.
check_map_case({{"a","apple"}, {"A","banana"}, {"B","banana"}}) should return false.
check_map_case({{"a","apple"}, {"8","banana"}, {"a","apple"}}) should return false.
check_map_case({{"Name","John"}, {"Age","36"}, {"City","Houston"}}) should return false.
check_map_case({{"STATE","NC"}, {"ZIP","12345"} }) should return true.
*/
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
bool check_dict_case(map<string,string> dict){

    map<string,string>::iterator it;
    int islower=0,isupper=0;
    if (dict.size()==0) return false;
    for (it=dict.begin();it!=dict.end();it++)
    {
        string key=it->first;
    
        for (int i=0;i<key.length();i++)
        {
            if (key[i]<65 or (key[i]>90 and key[i]<97) or key[i]>122) return false;
            if (key[i]>=65 and key[i]<=90) isupper=1;
            if (key[i]>=97 and key[i]<=122) islower=1;
            if (isupper+islower==2) return false;
        }

    }
    return true;
}
