#include <vector>
#include <string>

void numerical_letter_grade(std::vector<float>& grades, const std::vector<std::string>& names) {
    std::string gradeA = "A";
    std::string gradeB = "B";
    std::string gradeC = "C";
    std::string gradeD = "D";
    std::string gradeF = "F";

    for (size_t i = 0; i < grades.size(); ++i) {
        float grade = grades[i];
        if (grade >= 3.7) {
            names[i] = gradeA;
        } else if (grade >= 3.0) {
            names[i] = gradeB;
        } else if (grade >= 2.7) {
            names[i] = gradeC;
        } else if (grade >= 2.0) {
            names[i] = gradeD;
        } else {
            names[i] = gradeF;
        }
    }
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
