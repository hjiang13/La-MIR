```c++
#include <string>
#include <vector>

void find_max(std::string& result, std::vector<std::string>& input) {
    std::string maxString;
    int maxCount = 0;

    for (auto& str : input) {
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'x') {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            maxString = str;
        }
    }

    result = maxString;
}

int main() {
    std::vector<std::string> input = {"string1", "xxstringxx", "xstringx"};
    std::string result;
    find_max(result, input);
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
