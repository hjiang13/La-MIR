```cpp
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
```