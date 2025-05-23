/*
It is the last week of the semester and the teacher has to give the grades
to students. The teacher has been making her own algorithm for grading.
The only problem is, she has lost the code she used for grading.
She has given you a vector of GPAs for some students and you have to write 
a function that can output a vector of letter grades using the following table:
         GPA       |    Letter grade
          4.0                A+
        > 3.7                A 
        > 3.3                A- 
        > 3.0                B+
        > 2.7                B 
        > 2.3                B-
        > 2.0                C+
        > 1.7                C
        > 1.3                C-
        > 1.0                D+ 
        > 0.7                D 
        > 0.0                D-
          0.0                E


Example:
grade_equation({4.0, 3, 1.7, 2, 3.5}) ==> {"A+", "B", "C-", "C", "A-"}
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
vector<string> numerical_letter_grade(vector<float> grades){

    vector<string> out={};
    for (int i=0;i<grades.size();i++)
    {
        if (grades[i]>=3.9999) out.push_back("A+");
        if (grades[i]>3.7001 and grades[i]<3.9999) out.push_back("A");
        if (grades[i]>3.3001 and grades[i]<=3.7001) out.push_back("A-");
        if (grades[i]>3.0001 and grades[i]<=3.3001) out.push_back("B+");
        if (grades[i]>2.7001 and grades[i]<=3.0001) out.push_back("B");
        if (grades[i]>2.3001 and grades[i]<=2.7001) out.push_back("B-");
        if (grades[i]>2.0001 and grades[i]<=2.3001) out.push_back("C+");
        if (grades[i]>1.7001 and grades[i]<=2.0001) out.push_back("C");
        if (grades[i]>1.3001 and grades[i]<=1.7001) out.push_back("C-");
        if (grades[i]>1.0001 and grades[i]<=1.3001) out.push_back("D+");
        if (grades[i]>0.7001 and grades[i]<=1.0001) out.push_back("D");
        if (grades[i]>0.0001 and grades[i]<=0.7001) out.push_back("D-");
        if (grades[i]<=0.0001) out.push_back("E");
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
    assert (issame(numerical_letter_grade({4.0, 3, 1.7, 2, 3.5}) , {"A+", "B", "C-", "C", "A-"}));
    assert (issame(numerical_letter_grade({1.2}) , {"D+"}));
    assert (issame(numerical_letter_grade({0.5}) , {"D-"}));
    assert (issame(numerical_letter_grade({0.0}) , {"E"}));
    assert (issame(numerical_letter_grade({1, 0.3, 1.5, 2.8, 3.3}) , {"D", "D-", "C-", "B", "B+"}));
    assert (issame(numerical_letter_grade({0, 0.7}) , {"E", "D-"}));
    
}
