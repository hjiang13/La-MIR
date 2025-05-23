#include <vector>
#include <string>
#include <algorithm>

void find_max(std::string& result, const std::vector<std::string>& vec) {
    result = "";
    for (const auto& str : vec) {
        for (char ch : str) {
            if (std::find(result.begin(), result.end(), ch) == result.end()) {
                result += ch;
            }
        }
        if (str.length() > result.length() || (str.length() == result.length() && str < result)) {
            result = str;
        }
    }
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
