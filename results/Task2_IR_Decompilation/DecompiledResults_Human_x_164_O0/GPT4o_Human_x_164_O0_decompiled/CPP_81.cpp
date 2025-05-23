```cpp
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
```