#include <map>
#include <string>
#include <tuple>
#include <utility>

class histogram {
public:
    void operator()(std::map<char, int>& map, const std::string& str) {
        auto tuple1 = std::make_tuple();
        auto tuple2 = std::make_tuple();

        for (size_t i = 0; i < str.size(); ++i) {
            char c = str[i];
            auto it = map.find(c);
            if (it == map.end()) {
                map.emplace(std::piecewise_construct, std::forward_as_tuple(c), std::forward_as_tuple(1));
            } else {
                it->second += 1;
            }
        }
    }
};

int main() {
    std::map<char, int> char_count;
    std::string input_string = "example string to count characters";
    histogram h;
    h(char_count, input_string);

    // Output the histogram
    for (const auto& pair : char_count) {
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
