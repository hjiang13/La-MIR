#include <vector>
#include <string>

void numerical_letter_grade(std::vector<std::string>& grades, const std::vector<float>& scores) {
    for (size_t i = 0; i < scores.size(); ++i) {
        double score = static_cast<double>(scores[i]);

        if (score >= 4.0) {
            grades.push_back("A");
        } else if (score >= 3.7) {
            grades.push_back("A-");
        } else if (score >= 3.3) {
            grades.push_back("B+");
        } else if (score >= 3.0) {
            grades.push_back("B");
        } else if (score >= 2.7) {
            grades.push_back("B-");
        } else if (score >= 2.3) {
            grades.push_back("C+");
        } else if (score >= 2.0) {
            grades.push_back("C");
        } else if (score >= 1.7) {
            grades.push_back("C-");
        } else if (score >= 1.3) {
            grades.push_back("D+");
        } else if (score >= 1.0) {
            grades.push_back("D");
        } else {
            grades.push_back("F");
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
