```cpp
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
```