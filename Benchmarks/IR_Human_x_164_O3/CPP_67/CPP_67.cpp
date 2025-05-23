/*
In this task, you will be given a string that represents a number of apples and oranges 
that are distributed in a basket of fruit this basket contains 
apples, oranges, and mango fruits. Given the string that represents the total number of 
the oranges and apples and an integer that represent the total number of the fruits 
in the basket return the number of the mango fruits in the basket.
for example:
fruit_distribution("5 apples and 6 oranges", 19) ->19 - 5 - 6 = 8
fruit_distribution("0 apples and 1 oranges",3) -> 3 - 0 - 1 = 2
fruit_distribution("2 apples and 3 oranges", 100) -> 100 - 2 - 3 = 95
fruit_distribution("100 apples and 1 oranges",120) -> 120 - 100 - 1 = 19
*/
#include<stdio.h>
#include<string>
using namespace std;
int fruit_distribution(string s,int n){

    string num1="",num2="";
    int is12;
    is12=0;
    for (int i=0;i<s.size();i++)
        
        if (s[i]>=48 and s[i]<=57)
        {
            if (is12==0) num1=num1+s[i];
            if (is12==1) num2=num2+s[i];
        }
        else
          if (is12==0 and num1.length()>0) is12=1;
    return n-atoi(num1.c_str())-atoi(num2.c_str());

}
