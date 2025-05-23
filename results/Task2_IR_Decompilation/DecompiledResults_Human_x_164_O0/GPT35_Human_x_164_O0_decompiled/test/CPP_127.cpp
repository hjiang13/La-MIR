```c
#include <iostream>
#include <string>
#include <vector>

void intersection(std::string& result, std::vector<int>& vec1, std::vector<int>& vec2) {
    int max = std::max_element(vec1.begin(), vec1.end());
    int min = std::min_element(vec2.begin(), vec2.end());

    if (min - max < 2) {
        result = "NO";
    } else {
        result = "YES";
    }
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {3, 4, 5, 6, 7};

    std::string result;
    intersection(result, vec1, vec2);

    std::cout << result << std::endl;

    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (intersection({1, 2}, {2, 3}) == "NO");
    assert (intersection({-1, 1}, {0, 4}) == "NO");
    assert (intersection({-3, -1}, {-5, 5}) == "YES");
    assert (intersection({-2, 2}, {-4, 0}) == "YES");
    assert (intersection({-11, 2}, {-1, -1}) == "NO");
    assert (intersection({1, 2}, {3, 5}) == "NO");
    assert (intersection({1, 2}, {1, 2}) == "NO");
    assert (intersection({-2, -2}, {-3, -2}) == "NO");
}
