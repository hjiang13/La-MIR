/*
You have to write a function which validates a given date string and
returns true if the date is valid otherwise false.
The date is valid if all of the following rules are satisfied:
1. The date string is not empty.
2. The number of days is not less than 1 or higher than 31 days for months 1,3,5,7,8,10,12. And the number of days is not less than 1 or higher than 30 days for months 4,6,9,11. And, the number of days is not less than 1 or higher than 29 for the month 2.
3. The months should not be less than 1 or higher than 12.
4. The date should be in the format: mm-dd-yyyy

for example: 
valid_date("03-11-2000") => true

valid_date("15-01-2012") => false

valid_date("04-0-2040") => false

valid_date("06-04-2020") => true

valid_date("06/04/2020") => false
*/
#include<stdio.h>
#include<string>
using namespace std;
bool valid_date(string date){

    int mm,dd,yy,i;
    if (date.length()!=10) return false;
    for (int i=0;i<10;i++)
        if (i==2 or i==5)
        {
            if (date[i]!='-') return false;
        }
        else
            if (date[i]<48 or date[i]>57) return false;

    mm=atoi(date.substr(0,2).c_str());
    dd=atoi(date.substr(3,2).c_str());
    yy=atoi(date.substr(6,4).c_str());
    if (mm<1 or mm>12) return false;
    if (dd<1 or dd>31) return false;
    if (dd==31 and (mm==4 or mm==6 or mm==9 or mm==11 or mm==2)) return false;
    if (dd==30 and mm==2) return false;
    return true;

}
