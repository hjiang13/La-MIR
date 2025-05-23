#include <string>
#include <vector>
#include <cstring>

std::string find_max(std::string& result, const std::vector<std::string>& vec) {
    size_t max_length = 0;
    size_t index = 0;
    
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].length() > max_length) {
            max_length = vec[i].length();
            index = i;
        }
    }
    
    if (max_length > 0) {
        result = vec[index];
    } else {
        result.clear();
    }
    
    return result;
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
