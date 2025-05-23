#include <vector>
#include <string>
#include <cstring>

void intersection(std::string &result, const std::vector<int> &vec1, const std::vector<int> &vec2) {
    int size1 = vec1.size();
    int size2 = vec2.size();
    
    int minSize = (size1 < size2) ? size1 : size2;
    int value1 = vec1[0];
    int value2 = vec2[0];

    if (value1 < value2) {
        value1 = value2;
    }

    int next1 = vec1[1];
    int next2 = vec2[1];
    
    if (next1 < next2) {
        next1 = next2;
    }

    int diff = next1 - value1;
    
    if (diff < 2) {
        if (diff < 4) {
            result = "YES";
            result.resize(3);
            result[2] = '\0';
        } else {
            result = "YES";
            result.resize(3);
            result[2] = '\0';
        }
    } else {
        result = "YES";
        result.resize(3);
        result[2] = '\0';
    }

    result.resize(3);
    result[2] = '\0';
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
