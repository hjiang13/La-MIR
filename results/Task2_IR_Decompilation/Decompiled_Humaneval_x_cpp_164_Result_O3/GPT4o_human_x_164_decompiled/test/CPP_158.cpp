#include <iostream>
#include <vector>
#include <string>
#include <cstring>

void find_max(std::string& result, const std::vector<std::string>& vec) {
    size_t maxIndex = 0;
    size_t maxLength = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].size() > maxLength) {
            maxLength = vec[i].size();
            maxIndex = i;
        }
    }

    result = vec[maxIndex];
}

int main() {
    std::vector<std::string> vec = {"short", "longer", "longest"};
    std::string maxString;
    find_max(maxString, vec);
    std::cout << "Max string: " << maxString << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert ((find_max({"name", "of", "string"}) == "string"));
    assert ((find_max({"name", "enam", "game"}) == "enam"));
    assert ((find_max({"aaaaaaa", "bb", "cc"}) == "aaaaaaa"));
    assert ((find_max({"abc", "cba"}) == "abc"));
    assert ((find_max({"play", "this", "game", "of","footbott"}) == "footbott"));
    assert ((find_max({"we", "are", "gonna", "rock"}) == "gonna"));
    assert ((find_max({"we", "are", "a", "mad", "nation"}) == "nation"));
    assert ((find_max({"this", "is", "a", "prrk"}) == "this"));
    assert ((find_max({"b"}) == "b"));
    assert ((find_max({"play", "play", "play"}) == "play"));
}
