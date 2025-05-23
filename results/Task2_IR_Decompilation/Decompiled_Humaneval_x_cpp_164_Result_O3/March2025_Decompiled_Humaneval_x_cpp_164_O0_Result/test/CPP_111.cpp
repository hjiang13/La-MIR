#include <iostream>
#include <map>
#include <string>

std::map<char, int> histogram(const std::string &input) {
    std::map<char, int> frequencyMap;
    int maxFrequency = 0;

    for (char c : input) {
        if (c != ' ') {
            frequencyMap[c]++;
            if (frequencyMap[c] > maxFrequency) {
                maxFrequency = frequencyMap[c];
            }
        }
    }

    std::map<char, int> result;
    for (const auto &pair : frequencyMap) {
        if (pair.second == maxFrequency) {
            result[pair.first] = pair.second;
        }
    }

    return result;
}

int main() {
    std::string input = "example string";
    std::map<char, int> result = histogram(input);

    for (const auto &pair : result) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(map<char,int> a,map<char,int> b){
    if (a.size()!=b.size()) return false;
    map <char,int>::iterator it;
    for (it=a.begin();it!=a.end();it++)
    {
        char w1=it->first;
        int w2=it->second;
        if (b.find(w1)==b.end()) return false;
        if (b[w1]!=w2) return false;
    }

    return true;
}
int main(){
    assert (issame(histogram("a b b a") , {{'a',2},{'b', 2}}));
    assert (issame(histogram("a b c a b") , {{'a', 2},{'b', 2}}));
    assert (issame(histogram("a b c d g") , {{'a', 1}, {'b', 1}, {'c', 1}, {'d', 1}, {'g', 1}}));
    assert (issame(histogram("r t g") , {{'r', 1},{'t', 1},{'g', 1}}));
    assert (issame(histogram("b b b b a") , {{'b', 4}}));
    assert (issame(histogram("r t g") , {{'r', 1},{'t', 1},{'g', 1}}));
    assert (issame(histogram("") , {}));
    assert (issame(histogram("a") , {{'a', 1}}));
}
