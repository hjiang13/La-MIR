```cpp
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
```