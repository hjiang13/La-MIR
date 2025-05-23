#include <vector>
#include <string>
#include <algorithm>

std::string find_max(std::string& max_str, const std::vector<std::string>& vec) {
    max_str = "";
    size_t max_length = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        const std::string& current = vec[i];
        if (current.length() > max_length) {
            max_length = current.length();
            max_str = current;
        }
    }

    return max_str;
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
