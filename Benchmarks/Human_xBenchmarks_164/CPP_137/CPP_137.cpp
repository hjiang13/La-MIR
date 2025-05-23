/*
Create a function that takes integers, floats, or strings representing
real numbers, and returns the larger variable in its given variable type.
Return "None" if the values are equal.
Note: If a real number is represented as a string, the floating point might be . or ,

compare_one(1, 2.5) ➞ 2.5
compare_one(1, "2,3") ➞ "2,3"
compare_one("5,1", "6") ➞ "6"
compare_one("1", 1) ➞ "None"
*/
#include<stdio.h>
#include<string>
#include<algorithm>
#include<boost/any.hpp>
using namespace std;
boost::any compare_one(boost::any a,boost::any b){

    double  numa,numb;
    boost::any out;
   
    if (a.type()==typeid(string))
    {
        string s;
        s=boost::any_cast<string>(a);
        if (find(s.begin(),s.end(),',')!=s.end())
            for (int i=0;i<s.length();i++)
                if (s[i]==',') s=s.substr(0,i)+'.'+s.substr(i+1);
        numa=atof(s.c_str());
        
    }
    else 
    {
        if (a.type()==typeid(int)) numa=boost::any_cast<int>(a);
        if (a.type()==typeid(double)) numa=boost::any_cast<double>(a);
    }
    if (b.type()==typeid(string))
    {
        string s;
        s=boost::any_cast<string>(b);
        if (find(s.begin(),s.end(),',')!=s.end())
            for (int i=0;i<s.length();i++)
                if (s[i]==',') s=s.substr(0,i)+'.'+s.substr(i+1);
        numb=atof(s.c_str());
    }
    else 
    {
        if (b.type()==typeid(int)) numb=boost::any_cast<int>(b);
        if (b.type()==typeid(double)) numb=boost::any_cast<double>(b);
    }

    if (numa==numb) return string("None");
    if (numa<numb) return b;
    if (numa>numb) return a;
}
