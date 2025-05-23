```cpp
#include <vector>
#include <string>

void find_max(std::__cxx11::basic_string* result, std::vector<std::__cxx11::basic_string>* input) {
    std::__cxx11::basic_string* max_str = nullptr;
    for (auto str : *input) {
        if (max_str == nullptr || str.size() > max_str->size()) {
            max_str = &str;
        }
    }
    *result = *max_str;
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
