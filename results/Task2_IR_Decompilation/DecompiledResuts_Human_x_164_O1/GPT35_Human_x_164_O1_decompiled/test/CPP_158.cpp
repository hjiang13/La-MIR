```cpp
#include <string>
#include <vector>

void find_max(std::string& result, std::vector<std::string>& input) {
    std::string max_str;
    int max_length = 0;

    for (const std::string& str : input) {
        if (str.size() > max_length) {
            max_length = str.size();
            max_str = str;
        }
    }

    result = max_str;
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
