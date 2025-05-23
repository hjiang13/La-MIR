```cpp
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
```