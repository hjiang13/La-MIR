/*
Input is a space-delimited string of numberals from "zero" to "nine".
Valid choices are "zero", "one", 'two", 'three", "four", "five", 'six", 'seven", "eight" and "nine".
Return the string with numbers sorted from smallest to largest
>>> sort_numbers('three one five")
"one three five"
*/
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
string sort_numbers(string numbers){

    map<string,int> tonum={{"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}};
    map<int,string> numto={{0,"zero"},{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},{6,"six"},{7,"seven"},{8,"eight"},{9,"nine"}};
    int count[10];
    for (int i=0;i<10;i++)
        count[i]=0;
    string out="",current="";
    if (numbers.length()>0) numbers=numbers+' ';
    for (int i=0;i<numbers.length();i++)
        if (numbers[i]==' ')
        {
            count[tonum[current]]+=1;
            current="";
        }
        else current+=numbers[i];
    for (int i=0;i<10;i++)
        for (int j=0;j<count[i];j++)
            out=out+numto[i]+' ';
    if (out.length()>0) out.pop_back();
    return out;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (sort_numbers("") == "");
    assert (sort_numbers("three") == "three");
    assert (sort_numbers("three five nine") == "three five nine");
     assert (sort_numbers("five zero four seven nine eight") == "zero four five seven eight nine");
      assert (sort_numbers("six five four three two one zero") == "zero one two three four five six");
}
