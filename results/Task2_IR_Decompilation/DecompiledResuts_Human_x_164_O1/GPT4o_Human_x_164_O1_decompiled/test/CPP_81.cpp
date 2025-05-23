#include <vector>
#include <string>
#include <cstring>

void numerical_letter_grade(std::vector<float>& grades, const std::vector<std::string>& letters) {
    std::string letterA, letterB, letterC;
    std::vector<std::string> results;
    size_t i = 0;

    for (const auto& grade : grades) {
        if (grade < 3.999900) {
            letterA = "A";
            results.push_back(letterA);
        } else if (grade < 3.700100) {
            letterB = "B";
            results.push_back(letterB);
        } else if (grade < 3.300100) {
            letterC = "C";
            results.push_back(letterC);
        } else {
            results.push_back("F");
        }
        i++;
    }

    for (const auto& result : results) {
        // Handle result output
    }
}

int main() {
    std::vector<float> grades = {3.5, 4.0, 2.8, 3.9};
    std::vector<std::string> letters;
    numerical_letter_grade(grades, letters);
    return 0;
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
