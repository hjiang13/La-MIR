#include <vector>
#include <string>
#include <stdexcept>

std::vector<std::string> numerical_letter_grade(const std::vector<float>& grades) {
    std::vector<std::string> result;
    for (size_t i = 0; i < grades.size(); ++i) {
        float grade = grades[i];
        if (grade >= 3.9999) {
            result.push_back("A+");
        } else if (grade > 3.7001 && grade < 3.9999) {
            result.push_back("A");
        } else if (grade > 3.3001 && grade <= 3.7001) {
            result.push_back("A-");
        } else if (grade > 3.0001 && grade <= 3.3001) {
            result.push_back("B+");
        } else if (grade > 2.7001 && grade <= 3.0001) {
            result.push_back("B");
        } else if (grade > 2.3001 && grade <= 2.7001) {
            result.push_back("B-");
        } else if (grade > 2.0001 && grade <= 2.3001) {
            result.push_back("C+");
        } else if (grade > 1.7001 && grade <= 2.0001) {
            result.push_back("C");
        } else if (grade > 1.3001 && grade <= 1.7001) {
            result.push_back("C-");
        } else if (grade > 1.0001 && grade <= 1.3001) {
            result.push_back("D+");
        } else if (grade > 0.7001 && grade <= 1.0001) {
            result.push_back("D");
        } else if (grade > 0.0001 && grade <= 0.7001) {
            result.push_back("D-");
        } else if (grade <= 0.0001) {
            result.push_back("E");
        }
    }
    return result;
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
