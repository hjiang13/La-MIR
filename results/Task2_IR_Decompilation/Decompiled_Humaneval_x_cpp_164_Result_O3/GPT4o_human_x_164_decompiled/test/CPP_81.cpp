#include <vector>
#include <string>

void numerical_letter_grade(std::vector<float>& grades, const std::vector<std::string>& letters) {
    std::string letterA = "A";
    std::string letterB = "B";
    std::string letterC = "C";
    std::string letterD = "D";
    std::string letterF = "F";
    
    for (float grade : grades) {
        if (grade >= 3.7) {
            letters.push_back(letterA);
        } else if (grade >= 3.0) {
            letters.push_back(letterB);
        } else if (grade >= 2.3) {
            letters.push_back(letterC);
        } else if (grade >= 1.7) {
            letters.push_back(letterD);
        } else {
            letters.push_back(letterF);
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
